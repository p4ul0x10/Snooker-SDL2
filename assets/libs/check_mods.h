void pre_process_mods(int m1, int m2, float x[], float y[], int m[], float ax[], float ay[]){

  //start recursive pos check
  int mod_player;
  float rec_x, rec_y, center_xm1, center_xm2, center_ym1, center_ym2;

  mod_player = m1;

  //end recursive pos check
}

void recursive_pos(int m1, int m[], float x[], float y[], float ax[], float ay[]){

  if(m[m1] == 0){ // y - x +

    x[m1] = x[m1] - ax[m1];
    y[m1] = y[m1] + ay[m1];

  }else if(m[m1] == 1){ // y + x -

    x[m1] = x[m1] + ax[m1];
    y[m1] = y[m1] - ay[m1];

  }else if(m[m1] == 2){ // y - x -

    x[m1] = x[m1] + ax[m1];
    y[m1] = y[m1] + ay[m1];

  }else{ // y + x +

    x[m1] = x[m1] - ax[m1];
    y[m1] = y[m1] - ay[m1];
  }

}
