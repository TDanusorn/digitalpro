//#include "player.h"
//#include"SDFileSystem.h"
//#include "vs10xx.h"
//
//SDFileSystem sd(D11, D12, D13, D9, "sd"); // the pinout on the mbed Cool
//vs10xx vs1053(D11, D12, D13, D6, D7, D2, D8);//mosi,miso,sclk,xcs,xdcs,dreq,xreset 3spi+chip select
//Serial aa(USBTX, USBRX);
//Serial pc(D1, D0);
//playerStatetype  playerState;
//static unsigned char fileBuf[48000];
//unsigned char *bufptr;
//char green;
//uint8_t vol;
//bool startplaysong;
//bool playsong;
//char datainput;
//
//char list[20][50];            //song list
//
//char data ;
//DigitalIn sw_in(USER_BUTTON);
//
//void Player::begin(void)
//{
//    DirHandle *dir;
//    struct dirent *ptr;
//		FileHandle *fp;
//   
//    vs1053.reset();
//    dir = opendir("/sd");
//    //printf("\r\n**********playing list**********\r\n");
//    unsigned char i = 0,j=0;
//    while(((ptr = dir->readdir()) != NULL)&&(i <20))
//    {
//        if(strstr(ptr->d_name,".mp3")||strstr(ptr->d_name,".MP3"))
//        {
//							fp =sd.open(ptr->d_name, O_RDONLY);
//							if(fp != NULL) 
//							{
//								char *byte = ptr->d_name;
//                				j=0;
//                				while(*byte){
//                    				list[i][j++]  = *byte++;
//                    				green=i;
//                }
//                aa.printf("%2d . %s\r\n", i,list[i++]);
//				//fp->close();
//							}
//        }
//    }
//		dir->closedir();
//}
//
//
//
//
//
///*  select file by num.  */
//void Player::selectfile(char n){
//
//    startplaysong=false;
//    playerState =PS_STOP;
//    playsong=false;
//    green = n;
//    }
//    
//    
//    
///*  This function stop an audio file.  */
//void Player::stop(void){
//    startplaysong=true;
//    playerState =PS_STOP;
//    }
//    
//    
//void Player::run(){	
////			vs1053.setVolume(t);
//			if(datainput=='0'){
//				selectfile(0);
//				playFile(list[green]);
//    			//stop();
//				}
//			if(datainput=='1'){
//				selectfile(1);
//				playFile(list[green]);
//				//stop();
//				
//				}
//			if(datainput=='2'){
//				selectfile(2);
//				playFile(list[green]);
//    			//stop();
//				}
//			if(datainput=='3'){
//				selectfile(3);
//				playFile(list[green]);
//    			//stop();
//				}
//			if(datainput=='4'){
//				selectfile(4);
//				playFile(list[green]);
//    			//stop();
//				}
//			if(datainput=='5'){
//				selectfile(5);
//				playFile(list[green]);
//    			//stop();
//				}
//			else{
//				stop();
//				}
//}
//
//
//
//void Player::read(void){
//	pc.readable();
//	datainput = pc.getc();
//
//    }
//
//	
///*  This function plays audio file.  */
//void Player::playFile(char *file) {
//    int bytes;        // How many bytes in buffer left
//    char n;
//    
//    playerState = PS_PLAY;
//    
//    vs1053.setFreq(24000000);     //hight speed
//    
//    FileHandle *fp =sd.open(file, O_RDONLY);
//    
//    if(fp == NULL) {
//        printf("Could not open %s\r\n",file);
//
//    }
//    else
//    {
//        printf("Playing %s ...\r\n",file);
//        
//        /* Main playback loop */
//        while((bytes = fp->read(fileBuf,48000)) > 0) {	
//       {
//            //pc.printf("green\n");
//            if(pc.readable()){
//            	break;
//    			//stop();
//    			}
//    		vs1053.setFreq(24000000); 
//            bufptr = fileBuf;
//            // actual audio data gets sent to VS10xx.
//            while(bytes > 0)
//            {
//                n = (bytes < 32)?bytes:32; //defalt 32 
//                vs1053.writeData(bufptr,n);
//                bytes -= n;
//                bufptr += n;
//                if(pc.readable()){
//                	break;
//    				//stop();
//    			}
//                
//            }
//            uint8_t vol = 0;//set vlume
//			vs1053.setVolume(vol);  //set vlume
//		        
//            
//            if(playerState != PS_PLAY)         //stop
//            {
//                fp->close();
//                vs1053.softReset();
//            }
//            	
//			}
//        }
//    }
//
//}
//
