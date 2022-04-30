void assert_avoptions(AVDictionary *m)

{

    AVDictionaryEntry *t;

    if ((t = av_dict_get(m, "", NULL, AV_DICT_IGNORE_SUFFIX))) {

        av_log(NULL, AV_LOG_FATAL, "Option %s not found.\n", t->key);

        exit(1);

    }

}
