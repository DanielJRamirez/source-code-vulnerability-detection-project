static enum AVHWDeviceType hw_device_match_type_in_name(const char *codec_name)

{

    const char *type_name;

    enum AVHWDeviceType type;

    for (type = av_hwdevice_iterate_types(AV_HWDEVICE_TYPE_NONE);

         type != AV_HWDEVICE_TYPE_NONE;

         type = av_hwdevice_iterate_types(type)) {

        type_name = av_hwdevice_get_type_name(type);

        if (strstr(codec_name, type_name))

            return type;

    }

    return AV_HWDEVICE_TYPE_NONE;

}
