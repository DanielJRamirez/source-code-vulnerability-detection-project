static inline void direct_ref_list_init(H264Context * const h){

    MpegEncContext * const s = &h->s;

    Picture * const ref1 = &h->ref_list[1][0];

    Picture * const cur = s->current_picture_ptr;

    int list, i, j;

    if(cur->pict_type == I_TYPE)

        cur->ref_count[0] = 0;

    if(cur->pict_type != B_TYPE)

        cur->ref_count[1] = 0;

    for(list=0; list<2; list++){

        cur->ref_count[list] = h->ref_count[list];

        for(j=0; j<h->ref_count[list]; j++)

            cur->ref_poc[list][j] = h->ref_list[list][j].poc;

    }

    if(cur->pict_type != B_TYPE || h->direct_spatial_mv_pred)

        return;

    for(list=0; list<2; list++){

        for(i=0; i<ref1->ref_count[list]; i++){

            const int poc = ref1->ref_poc[list][i];

            h->map_col_to_list0[list][i] = PART_NOT_AVAILABLE;

            for(j=0; j<h->ref_count[list]; j++)

                if(h->ref_list[list][j].poc == poc){

                    h->map_col_to_list0[list][i] = j;

                    break;

                }

        }

    }

}
