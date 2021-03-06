//鬼の更新(AIと同じ)ただし鬼が２倍のペースで更新
#include "Data.h"

void update_Tagger(Tagger *tagger,int Stage[WIDTH][HEIGHT]){

	tagger->step+=4;
	switch(tagger->act){
	case N:
		tagger->s_y-=4;
		break;
	case E:
		tagger->s_x+=4;
		break;
	case S:
		tagger->s_y+=4;
		break;
	case W:
		tagger->s_x-=4;
		break;
	case STOP:
		tagger->act=STOP; //	toshi : AIに止まるという選択肢がなかったので追加
	default:
		break;
	}
	tagger->x=tagger->s_x/BOX;
	tagger->y=tagger->s_y/BOX;
	
	if(Stage[tagger->x][tagger->y]==1){
		switch(tagger->act){//7/27 zero:衝突後の座標を進行方向で決定するように修正
		case N:
			tagger->y++;
			break;
		case E:
			tagger->x--;
			break;
		case S:
			tagger->y--;
			break;
		case W:
			tagger->x++;
			break;
		default:
			break;
		}
		tagger->act=STOP;
		tagger->s_x=(tagger->x+0.5)*BOX;
		tagger->s_y=(tagger->y+0.5)*BOX;
	}

	if(tagger->step==BOX){
		tagger->act=STOP;
		tagger->step=0;
	}

}