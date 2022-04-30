static int decode_exponents(AC3DecodeContext *ctx)

{

    ac3_audio_block *ab = &ctx->audio_block;

    int i;

    uint8_t *exps;

    uint8_t *dexps;



    if (ab->flags & AC3_AB_CPLINU && ab->cplexpstr != AC3_EXPSTR_REUSE)

        if (_decode_exponents(ab->cplexpstr, ab->ncplgrps, ab->cplabsexp,

                    ab->cplexps, ab->dcplexps + ab->cplstrtmant))

            return -1;

    for (i = 0; i < ctx->bsi.nfchans; i++)

        if (ab->chexpstr[i] != AC3_EXPSTR_REUSE) {

            exps = ab->exps[i];

            dexps = ab->dexps[i];

            if (_decode_exponents(ab->chexpstr[i], ab->nchgrps[i], exps[0], exps + 1, dexps + 1))

                return -1;

        }

    if (ctx->bsi.flags & AC3_BSI_LFEON && ab->lfeexpstr != AC3_EXPSTR_REUSE)

        if (_decode_exponents(ab->lfeexpstr, 2, ab->lfeexps[0], ab->lfeexps + 1, ab->dlfeexps))

            return -1;

    return 0;

}
