static void generate_offset_lut(DiracGolombLUT *lut, int off)

{

    int idx;

    for (idx = 0; idx < LUT_SIZE; idx++) {

        DiracGolombLUT *l = &lut[idx];



        INIT_RESIDUE(res);

        SET_RESIDUE(res, idx, LUT_BITS);



        l->preamble      = CONVERT_TO_RESIDUE(res >> (RSIZE_BITS - off), off);

        l->preamble_bits = off;

        l->sign = ((l->preamble >> (RSIZE_BITS - l->preamble_bits)) & 1) ? -1 : +1;



        search_for_golomb(l, res << off, LUT_BITS - off);

    }

}
