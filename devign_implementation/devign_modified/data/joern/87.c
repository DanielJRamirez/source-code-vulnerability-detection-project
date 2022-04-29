static inline void RENAME(rgb24ToUV_half)(uint8_t *dstU, uint8_t *dstV, const uint8_t *src1, const uint8_t *src2, int width, uint32_t *unused)

{

    int i;

    assert(src1==src2);

    for (i=0; i<width; i++) {

        int r= src1[6*i + 0] + src1[6*i + 3];

        int g= src1[6*i + 1] + src1[6*i + 4];

        int b= src1[6*i + 2] + src1[6*i + 5];



        dstU[i]= (RU*r + GU*g + BU*b + (257<<RGB2YUV_SHIFT))>>(RGB2YUV_SHIFT+1);

        dstV[i]= (RV*r + GV*g + BV*b + (257<<RGB2YUV_SHIFT))>>(RGB2YUV_SHIFT+1);

    }

}
