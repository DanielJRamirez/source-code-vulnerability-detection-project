int hw_device_setup_for_encode(OutputStream *ost)

{

    enum AVHWDeviceType type;

    HWDevice *dev;



    type = hw_device_match_type_in_name(ost->enc->name);

    if (type != AV_HWDEVICE_TYPE_NONE) {

        dev = hw_device_get_by_type(type);

        if (!dev) {

            av_log(ost->enc_ctx, AV_LOG_WARNING, "No device available "

                   "for encoder (device type %s for codec %s).\n",

                   av_hwdevice_get_type_name(type), ost->enc->name);

            return 0;

        }

        ost->enc_ctx->hw_device_ctx = av_buffer_ref(dev->device_ref);

        if (!ost->enc_ctx->hw_device_ctx)

            return AVERROR(ENOMEM);

        return 0;

    } else {

        // No device required.

        return 0;

    }

}
