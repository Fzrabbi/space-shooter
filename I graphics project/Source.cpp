#include "iGraphics.h"
#include<stdlib.h>

int x,y,shipx=400,shipy=10,bugship1x,bugship1y=600,bugship2x=60,bugship2y=800,count=0,respawn_counter=0,bug_ship1_respawncounter=0,bug_ship2_respawncounter=0,enemy_boss1_respawncounter=0,firex=shipx,firey=shipy+10,score=0;
int eboss1x=400,eboss1y=350,sx=1,boss_firex=eboss1x,boss_firey=eboss1y,boss_hit=0,gameovercount=0;
bool start = true,option=false,about=false,blast=false,blast_bug_ship1=false,blast_bug_ship2=false,blast_enemy_boss1=false,gameover=false,level1=false,level2=false,level3=false,level4=false,level5=false,level6=false,level7=false,level8=false,level9=false,level10=false,victory=false;
char scoreText[100];
void rand_bugship1();
void rand_bugship2();
void rand_bossfire();
void rand_fire();
void iDraw()
{
	iClear();
	if(start==true)
	{//main menue background
		x;y;shipx=400;shipy=10;bugship1x;bugship1y=1000;bugship2x=60;bugship2y=900;count=0;respawn_counter=0,score=0;
		blast=false;


		if(option==false){
			iShowBMP(0, 0,"image\\space_menu_background.bmp");
		}
	    if(option==true){
			iShowBMP(0,0, "image\\option.bmp");
	    }
		if(about==true){
            iShowBMP(0,0, "image\\about_background.bmp");
		}
	}
	if(start==false)
	{
			iShowBMP(0, 0,"image\\game_background.bmp");//game sart background	
			iSetColor(255,0,0);//Score show
	        iText(705,475,"Score:");
	        _itoa_s(score,scoreText,10);
	        iText(755,475,scoreText);
            //for shoing victory
			if(score>=2000){
				victory=true;
			}
			if(victory==true){
				iShowBMP(100, 100,"image\\victory.bmp");
			}
			//for showing heart//
			if(count==0){
				iShowBMP(80, 475,"image\\heart.bmp");
				iShowBMP(110, 475,"image\\heart.bmp");
			    iShowBMP(140, 475,"image\\heart.bmp");
			}
		    if(count==1){
				iShowBMP(80, 475,"image\\heart.bmp");
				iShowBMP(110, 475,"image\\heart.bmp");
			}
			if(count==2){
			    iShowBMP(80, 475,"image\\heart.bmp");
			}
			//level setting
			if(score>=0&&score<200){
				iShowBMP(170, 470,"image\\level1.bmp");
				level1=true;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=false;

			}
			if(score>=200&&score<400){
				iShowBMP(170, 470,"image\\level2.bmp");
				level1=false;
				level2=true;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=400&&score<600){
				iShowBMP(170, 470,"image\\level3.bmp");
				level1=false;
				level2=false;
				level3=true;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=600&&score<800){
				iShowBMP(170, 470,"image\\level4.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=true;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=800&&score<1000){
				iShowBMP(170, 470,"image\\level5.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=true;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=1000&&score<1200){
				iShowBMP(170, 470,"image\\level6.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=true;
				level7=false;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=1200&&score<1400){
				iShowBMP(170, 470,"image\\level7.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=true;
				level8=false;
				level9=false;
				level10=false;
			}
			if(score>=1400&&score<1600){
				iShowBMP(170, 470,"image\\level8.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=true;
				level9=false;
				level10=false;
			}
			if(score>=1600&&score<1800){
				iShowBMP(170, 470,"image\\level9.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=true;
				level10=false;
			}
			if(score>=1800&&score<2000){
				iShowBMP(170, 470,"image\\level10.bmp");
				level1=false;
				level2=false;
				level3=false;
				level4=false;
				level5=false;
				level6=false;
				level7=false;
				level8=false;
				level9=false;
				level10=true;
			}
			//game over show
			if(gameover==true){
				gameovercount++;
				iShowBMP(100, 100,"image\\gameover.bmp");
				iSetColor(255,0,0);//Score show
	            iText(350,200,"Total Score:");
	            _itoa_s(score,scoreText,10);
	            iText(460,199,scoreText);
				if(gameovercount>150){
					gameover=false;
					start=true;
					gameovercount=0;
					boss_hit=0;
				}
			}
		    //*************LEVEL   01***************
			if(level1==true){
			
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=3,"ships\\bug_ship01.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=2,"ships\\bug_ship01.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship01.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=3,"ships\\bug_ship2.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship2.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=50)
				{
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss1.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=5,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss1.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//****************level 02*****************
		if(level2==true){
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=4,"ships\\bug_ship3.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=4,"ships\\bug_ship3.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship3.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=4,"ships\\bug_ship4.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship4.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=250&&score<300)
				{
				    eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss2.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=8,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss2.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn boss2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 3***********
		if(level3==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship5.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship5.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship5.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship6.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship6.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=450&&score<500)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss3.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss3.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 4************
		if(level4==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship7.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship7.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship7.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship8.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship8.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=650&&score<700)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss4.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss4.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 5***********
		if(level5==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship9.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship9.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship9.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship10.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship10.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=850&&score<900)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss5.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss5.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 6*********
			if(level6==true){
			
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=3,"ships\\bug_ship01.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=2,"ships\\bug_ship01.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship01.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=3,"ships\\bug_ship2.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship2.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=1050&&score<1100)
				{
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss6.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=5,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss6.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//****************level 7*****************
		if(level7==true){
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=4,"ships\\bug_ship3.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=4,"ships\\bug_ship3.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship3.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=4,"ships\\bug_ship4.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship4.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=1250&&score<1300)
				{
				    eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss7.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=8,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss7.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn boss2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 8***********
		if(level8==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship5.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship5.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship5.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship6.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship6.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=1450&&score<1500)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss8.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss8.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 9************
		if(level9==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship7.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship7.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship7.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship8.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship8.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=1650&&score<1700)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss9.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss9.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
		//**********level 10***********
		if(level10==true){
			eboss1y=350;
				if(blast==false){
					iShowBMP(shipx,shipy,"ships\\spaceship1.bmp");
				}
				else
				{
					iShowBMP(shipx,shipy,"ships\\blast.bmp");//blast my ship
					respawn_counter++;
					if(respawn_counter>100)//respawn my ship
					{
						blast=false;
						respawn_counter=0;
					}
				} 
				//bug ship 1
				if(blast_bug_ship1==false){
					if(bugship1y<-80)
						rand_bugship1();
					else
					{
						if(bugship1x > 800 || bugship1x < 0)
						{
							bugship1x=-bugship1x;
						}
						else
						{
							if(bugship1y<450)
								iShowBMP(bugship1x+=1,bugship1y-=6,"ships\\bug_ship9.bmp");
							else
								iShowBMP(bugship1x-=1,bugship1y-=6,"ships\\bug_ship9.bmp");
						}
					}
				}
				else{
					iShowBMP(bugship1x,bugship1y,"ships\\blast_bug_ship9.bmp");//blast bug ship1
					bug_ship1_respawncounter++;
					if(bug_ship1_respawncounter>30)//respawn bug ship1
					{
						blast_bug_ship1=false;
						bug_ship1_respawncounter=0;
						bugship1y=-950;
					}

				}
				//bugship2
				if(blast_bug_ship2==false){                                                                           
					if(bugship2y<-100)
						rand_bugship2();
					else
					{
				    iShowBMP(bugship2x,bugship2y-=6,"ships\\bug_ship10.bmp");
					}
				}
				else{
					iShowBMP(bugship2x,bugship2y,"ships\\blast_bug_ship10.bmp");//blast bug ship2
					bug_ship2_respawncounter++;
					if(bug_ship2_respawncounter>30)//respawn bug ship2
					{
						blast_bug_ship2=false;
						bug_ship2_respawncounter=0;
						bugship2y=-1000;
					}
				}
				///if crash life lost
				if(((bugship2x+64>=shipx)&&(bugship2x<=shipx+64))&&((bugship2y<=shipy+82)&&(bugship2y+67>=shipy)))
				{
					if(blast==false)
					{
						count++;
						blast=true;
					}
					bugship2y=-1000;
					if(count==3){
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				if(((bugship1x+64>=shipx)&&(bugship1x<=shipx+64))&&((bugship1y<=shipy+82)&&(bugship1y+67>=shipy)))
				{
					if(blast==false)
					{
						blast=true;
						count++;
					}
					bugship1y=-1000;
					if(count==3)
					{
						gameover=true;
						//start=true;;
						option=false;
						count=0;
						shipy=1500;
					}
				}
				//for my fire
				if(firey>500)
					rand_fire();
				else
				{
					iShowBMP(firex+45,firey+=25,"ships\\fire.bmp");
					iShowBMP(firex+10,firey,"ships\\fire.bmp");
				}
				//distroy enemy ship & score++
				if(((firex+64>=bugship2x)&&(firex<=bugship2x+64))&&((firey<=bugship2y+67)&&(firey+35>=bugship2y)))
				{
					if(blast_bug_ship2==false)
					{
						blast_bug_ship2=true;
						score+=2;
					}
					firey=600;
				}
				if(((firex+64>=bugship1x)&&(firex<=bugship1x+64))&&((firey<=bugship1y+67)&&(firey+35>=bugship1y)))
				{
					if(blast_bug_ship1==false)
					{
						blast_bug_ship1=true;
						score+=5;
					}
					firey=600;
				}
				//boss 1 show
				if(score>=1850&&score<1900)
				{
					eboss1y=350;
					if(blast_enemy_boss1==false)
					{
						if(eboss1x>544||eboss1x<0)
						{
							//iShowBMP(ebossx++,ebossy,"ships//enemy_boss1");
							sx=-sx;
						}
						iShowBMP(eboss1x+=sx,eboss1y,"ships//enemy_boss10.bmp");
						//boss1 fire
						if(boss_firey<0)
						{
							rand_bossfire();
						}
						else
						{
							iShowBMP(boss_firex+84,boss_firey-=10,"ships\\boss_fire.bmp");
							iShowBMP(boss_firex+172,boss_firey,"ships\\boss_fire.bmp");
						}
						//boss fire destroy my ship
						int x=boss_firex+84,x2=boss_firex+172;
						if(((x-10>=shipx)&&(x<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy))||((x2-10>=shipx)&&(x2<=shipx+54))&&((boss_firey<=shipy+82)&&(boss_firey+18>=shipy)))
						{
							if(blast==false)
							{
								blast=true;
								count++;
							}
							boss_firey=-1500;
							if(count==3)
							{
								gameover=true;
								//start=true;;
								option=false;
								count=0;
								shipy=1500;
							}					
						}
					}
			    
					else
					{
						iShowBMP(eboss1x,eboss1y,"ships\\blast_enemy_boss10.bmp");//blast boss ship1
						enemy_boss1_respawncounter++;
						if(enemy_boss1_respawncounter>30)//respawn bug ship2
						{
							blast_enemy_boss1=false;
							enemy_boss1_respawncounter=0;
							eboss1y=-1000;
						}
					}
			
					//my fire distroy boss ship
					if(((firex+64>=eboss1x)&&(firex<=eboss1x+256))&&((firey<=eboss1y+67)&&(firey+23>=eboss1y)))
					{
						boss_hit++;
						if(blast_enemy_boss1==false && boss_hit==40)
						{
							blast_enemy_boss1=true;
							score+=100;
							boss_hit=0;
						}
						firey=600;
				  
					}
				}
					//
		}
	}
	 system("CLS");			
	printf("bugship1x= %d\n",bugship1x);
	printf("respawn counter = %d / 100\n",respawn_counter);
    printf("life count= %d\n",count);
	printf("bugship1y = %d\n",bugship1y);
	printf("bugship2y = %d\n",bugship2y);
	printf("score = %d\n",score);
	printf("boss hit = %d\n",boss_hit);
	printf("respawn counter = %d / 100\n",enemy_boss1_respawncounter);
	
}

void iMouseMove(int mx, int my)
{
//place your codes here
}
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
    {
			if(start==true && option==false && about==false){
				if(mx>652 && mx<710 && my>285 && my<311){
					exit(0);//quit
		        }
	            if(mx>645 && 723>mx && my<352 && my>322)
			    {
			    option= true;//for instruction
			    PlaySound("music\\option_sound",NULL, SND_LOOP | SND_ASYNC);
			    }
				if(mx>626 && 736>mx && my<470 && my>445){
				start=false;//start game
				PlaySound("music\\game_sound", NULL, SND_LOOP | SND_ASYNC);
			    }
				if(mx>0 && 52>mx && my<30 && my>0)
			    {
			    about= true;//about
				PlaySound("music\\option_sound",NULL, SND_LOOP | SND_ASYNC );
				}
	         }
			if(option == true && about==false && start==true)
		    {
			    if(mx>725 && 790>mx && my<33 && my>11){
				option = false;
			    PlaySound("music\\home_sound", NULL, SND_LOOP | SND_ASYNC);
				}
		    }
			if(about==true){
				if(mx>730 && 795>mx && my<497 && my>470){
					start=true;
					about=false;
					PlaySound("music\\home_sound", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			if(start==false && about==false && option==false){
				if(mx>7 && 56>mx && my <491 && my>474){
					start=true;
					PlaySound("music\\home_sound", NULL, SND_LOOP | SND_ASYNC);
				}
			}
		    system("CLS");
			printf("\n\n\n\n\nMouse X=%d\nMouse Y= %d",mx,my);	
	}
}
void rand_bugship1()
{
	//if(bugship1y<-150)
	int i;
	
	i=rand()%736+20;
	if(i%6==0)
	{
		bugship1x=i;
		bugship1y=650;
	}
}
void rand_bugship2()
{
	//if(bugship1y<-150)
	int i;	
	i=rand()%736+20;
	if(i%9==0)
	{
		bugship2x=i;
		bugship2y=750;
	}
}
void rand_fire(){
	firex=shipx;
	firey=shipy;
}
void rand_bossfire(){
	boss_firex=eboss1x;
	boss_firey=eboss1y;
}


void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		//do something with 'q'
		iPauseTimer(0);
    }
	if(key == 'r')
    {
		iResumeTimer(0);
	}
}
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_RIGHT && shipx<=800-64)	
	{
		shipx+=20;
	}
	if(key == GLUT_KEY_LEFT && shipx>=1)
	{
		shipx-=20;
	}
	if(key == GLUT_KEY_UP && shipy<=500-90)
	{
		shipy+=10;
	}
	if(key == GLUT_KEY_DOWN && shipy>=1)
	{
		shipy-=10;
	}
}
int main()
{
	if(start == true)
    {
	   srand(time(NULL));
	   PlaySound("music\\home_sound", NULL, SND_LOOP | SND_ASYNC);
    }
    iInitialize(800, 500);
    return 0;
}