static void process_subpacket_9 (QDM2Context *q, QDM2SubPNode *node)

{

    GetBitContext gb;

    int i, j, k, n, ch, run, level, diff;



    init_get_bits(&gb, node->packet->data, node->packet->size*8);



    n = coeff_per_sb_for_avg[q->coeff_per_sb_select][QDM2_SB_USED(q->sub_sampling) - 1] + 1; // same as averagesomething function



    for (i = 1; i < n; i++)

        for (ch=0; ch < q->nb_channels; ch++) {

            level = qdm2_get_vlc(&gb, &vlc_tab_level, 0, 2);

            q->quantized_coeffs[ch][i][0] = level;



            for (j = 0; j < (8 - 1); ) {

                run = qdm2_get_vlc(&gb, &vlc_tab_run, 0, 1) + 1;

                diff = qdm2_get_se_vlc(&vlc_tab_diff, &gb, 2);



                for (k = 1; k <= run; k++)

                    q->quantized_coeffs[ch][i][j + k] = (level + ((k*diff) / run));



                level += diff;

                j += run;

            }

        }



    for (ch = 0; ch < q->nb_channels; ch++)

        for (i = 0; i < 8; i++)

            q->quantized_coeffs[ch][0][i] = 0;

}
