static int read_code_table(CLLCContext *ctx, GetBitContext *gb, VLC *vlc)
{
    uint8_t symbols[256];
    uint8_t bits[256];
    uint16_t codes[256];
    int num_lens, num_codes, num_codes_sum, prefix;
    int i, j, count;
    prefix        = 0;
    count         = 0;
    num_codes_sum = 0;
    num_lens = get_bits(gb, 5);
    for (i = 0; i < num_lens; i++) {
        num_codes      = get_bits(gb, 9);
        num_codes_sum += num_codes;
        if (num_codes_sum > 256) {
            av_log(ctx->avctx, AV_LOG_ERROR,
                   "Too many VLCs (%d) to be read.\n", num_codes_sum);
        for (j = 0; j < num_codes; j++) {
            symbols[count] = get_bits(gb, 8);
            bits[count]    = i + 1;
            codes[count]   = prefix++;
            count++;
        if (prefix > (65535 - 256)/2) {
        prefix <<= 1;
    return ff_init_vlc_sparse(vlc, VLC_BITS, count, bits, 1, 1,
                              codes, 2, 2, symbols, 1, 1, 0);