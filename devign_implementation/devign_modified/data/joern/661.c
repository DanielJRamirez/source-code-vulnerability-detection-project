static inline void cvtyuvtoRGB (SwsContext *c,

			   vector signed short Y, vector signed short U, vector signed short V,

			   vector signed short *R, vector signed short *G, vector signed short *B)

{

  vector signed   short vx,ux,uvx;



  Y = vec_mradds (Y, c->CY, c->OY);

  U  = vec_sub (U,(vector signed short)

  			vec_splat((vector signed short)AVV(128),0));

  V  = vec_sub (V,(vector signed short)

  			vec_splat((vector signed short)AVV(128),0));



  //   ux  = (CBU*(u<<c->CSHIFT)+0x4000)>>15;

  ux = vec_sl (U, c->CSHIFT);

  *B = vec_mradds (ux, c->CBU, Y);



  // vx  = (CRV*(v<<c->CSHIFT)+0x4000)>>15;

  vx = vec_sl (V, c->CSHIFT);

  *R = vec_mradds (vx, c->CRV, Y);



  // uvx = ((CGU*u) + (CGV*v))>>15;

  uvx = vec_mradds (U, c->CGU, Y);

  *G = vec_mradds (V, c->CGV, uvx);

}
