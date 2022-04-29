static inline void h264_loop_filter_chroma_c(uint8_t *pix, int xstride, int ystride, int alpha, int beta, int8_t *tc0)

{

    int i, d;

    for( i = 0; i < 4; i++ ) {

        const int tc = tc0[i];

        if( tc <= 0 ) {

            pix += 2*ystride;

            continue;

        }

        for( d = 0; d < 2; d++ ) {

            const int p0 = pix[-1*xstride];

            const int p1 = pix[-2*xstride];

            const int q0 = pix[0];

            const int q1 = pix[1*xstride];



            if( FFABS( p0 - q0 ) < alpha &&

                FFABS( p1 - p0 ) < beta &&

                FFABS( q1 - q0 ) < beta ) {



                int delta = av_clip( (((q0 - p0 ) << 2) + (p1 - q1) + 4) >> 3, -tc, tc );



                pix[-xstride] = av_clip_uint8( p0 + delta );    /* p0' */

                pix[0]        = av_clip_uint8( q0 - delta );    /* q0' */

            }

            pix += ystride;

        }

    }

}
