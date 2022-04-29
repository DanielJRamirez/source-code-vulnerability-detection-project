static int count_paired_channels(uint8_t (*layout_map)[3], int tags, int pos, int *current) {

    int num_pos_channels = 0;

    int first_cpe = 0;

    int sce_parity = 0;

    int i;

    for (i = *current; i < tags; i++) {

        if (layout_map[i][2] != pos)

            break;

        if (layout_map[i][0] == TYPE_CPE) {

            if (sce_parity) {

                if (pos == AAC_CHANNEL_FRONT || !first_cpe) {

                    sce_parity = 0;

                } else {

                    return -1;

                }

            }

            num_pos_channels += 2;

            first_cpe = 1;

        } else {

            num_pos_channels++;

            sce_parity ^= 1;

        }

    }

    if (sce_parity &&

        ((pos == AAC_CHANNEL_FRONT && first_cpe) || pos == AAC_CHANNEL_SIDE))

            return -1;

    *current = i;

    return num_pos_channels;

}
