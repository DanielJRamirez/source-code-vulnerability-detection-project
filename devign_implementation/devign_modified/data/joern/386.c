static int mkv_check_tag(AVDictionary *m)

{

    AVDictionaryEntry *t = NULL;



    while ((t = av_dict_get(m, "", t, AV_DICT_IGNORE_SUFFIX)))

        if (av_strcasecmp(t->key, "title") && av_strcasecmp(t->key, "stereo_mode"))

            return 1;



    return 0;

}
