av_cold void ff_float_dsp_init_ppc(AVFloatDSPContext *fdsp, int bit_exact)

{

#if HAVE_ALTIVEC

    if (!(av_get_cpu_flags() & AV_CPU_FLAG_ALTIVEC))

        return;



    fdsp->vector_fmul = ff_vector_fmul_altivec;

    fdsp->vector_fmul_add = ff_vector_fmul_add_altivec;

    fdsp->vector_fmul_reverse = ff_vector_fmul_reverse_altivec;



    if (!bit_exact) {

        fdsp->vector_fmul_window = ff_vector_fmul_window_altivec;

    }

#endif

}
