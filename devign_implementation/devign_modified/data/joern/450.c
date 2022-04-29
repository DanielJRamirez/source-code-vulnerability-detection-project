static const HWAccel *get_hwaccel(enum AVPixelFormat pix_fmt)

{

    int i;

    for (i = 0; hwaccels[i].name; i++)

        if (hwaccels[i].pix_fmt == pix_fmt)

            return &hwaccels[i];

    return NULL;

}
