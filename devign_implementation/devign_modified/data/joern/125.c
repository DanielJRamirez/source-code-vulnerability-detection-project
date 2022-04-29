static int mxf_read_content_storage(MXFContext *mxf, ByteIOContext *pb, int tag)

{

    switch (tag) {

    case 0x1901:

        mxf->packages_count = get_be32(pb);

        if (mxf->packages_count >= UINT_MAX / sizeof(UID))

            return -1;

        mxf->packages_refs = av_malloc(mxf->packages_count * sizeof(UID));

        if (!mxf->packages_refs)

            return -1;

        url_fskip(pb, 4); /* useless size of objects, always 16 according to specs */

        get_buffer(pb, (uint8_t *)mxf->packages_refs, mxf->packages_count * sizeof(UID));

        break;

    }

    return 0;

}
