av_cold void ff_af_queue_init(AVCodecContext *avctx, AudioFrameQueue *afq)

{

    afq->avctx             = avctx;

    afq->next_pts          = AV_NOPTS_VALUE;

    afq->remaining_delay   = avctx->delay;

    afq->remaining_samples = avctx->delay;

    afq->frame_queue       = NULL;

}
