void timer(){
  if(/*timer is fresh*/){
    //turn data pins high
    //set timmer interrupt time for .4us
    if(cereal=0){
      //turn data pins low
      //set timer interrupt time for 301us
    }
    if(cerealcount=cereal)
      cereal = 0;
    else
      ++cereal;
  }elif(/*timer is .4us*/){
    //datapins = supercereal[cereal];
    //set timer interrupt time for .8us
  }elif(/*timer is .8us*/){
    //turn data pins low
    //set
  }elif(/*timer is 301us*/)
    //set timer count to nearly expire
}

void SPIcomms(){
  switch(SPIstatus)
  {
    case 1:
      //start SPI read
      SPDR = 0xFF;
      SPIstatus = 2;
      break;
    case 2:
      //start SPI read
      SPIstatus = 3;
      break;
    case 3:
      //start SPI read
      SPIstatus = 4;
      break;
    case 4:
      //start SPI read
      SPIstatus = 5;
      break;
    case 5:
      //start SPI read
      SPIstatus = 6;
      break;
    case 6:
      //start SPI read
      SPIstatus = 255;
      break;
    case default:
      if(){//read if timer for ~120Hz has reached max to begin reading VESC through SPI
        SPIstatus = 1;
        //reset timer counter
      }
      break;
}

void HSVtoRGB(){
    if(Value==0)
        RedBrightness = GreenBrightness = BlueBrightness = 0;
    else{
        uint16_t tmp16;
        uint8_t HueDivCount,Y,Z;
        //solve for Y, Y = (Value*(255-Saturation))/255;
        Y = 255-Saturation;
        tmp16 = Value*Y;//top is 65025
        while(tmp16>254){//divide by 255
            tmp16 -= 255;
            ++Y;
        }
        if(tmp16>127)//round the remainder
            ++Y;
        //solve to get appropriate action for HSV to RGB, Hue/6
        tmp16 = Hue;
        HueDivCount = 0;
        while(tmp16>10922){
            tmp16 -= 10923;//if HueDivCount=5 top is 10920 (2/65535)0.00003051%/(2/10922)0.0001831% deviation from real due to integer only math
            ++HueDivCount;
        }
        if(HueDivCount==5)//offset number so maximum value stays true
            tmp16 += 2;
        //solve for Z, Z = (Value*(Saturation*HueRemain))/2785110, if HueDivCount=1,3,5 then invert the value
        Z = 0;
        while(tmp16>42){//divide to 8 bit size so next operation does not exceed 16 bit size
            tmp16 -= 43;
            ++Z;
        }
        if(tmp16>21)//round the remainder
            ++Z;
        tmp16 = Z*Saturation;
        Z = 0;
        while(tmp16>253){//divide to 8 bit size so next operation does not exceed 16 bit size
            tmp16 -= 254;
            ++Z;
        }
        if(tmp16>126)//round the remainder
            ++Z;
        tmp16 = Z*Value;
        while(tmp16>254){//divide to 8 bit size so next operation does not exceed 16 bit size
            tmp16 -= 255;
            ++Z;
        }
        if(tmp16>127)//round the remainder
            ++Z;
        switch(HueDivCount){
            case 0:
                RedBrightness = Value;
                GreenBrightness = Z;
                BlueBrightness = Y;
                break;
            case 1:
                RedBrightness = 255-Z;
                GreenBrightness = Value;
                BlueBrightness = Y;
                break;
            case 2:
                RedBrightness = Y;
                GreenBrightness = Value;
                BlueBrightness = Z;
                break;
            case 3:
                RedBrightness = Y;
                GreenBrightness = 255-Z;
                BlueBrightness = Value;
                break;
            case 4:
                RedBrightness = Z;
                GreenBrightness = Y;
                BlueBrightness = Value;
                break;
            case 5:
                RedBrightness = Value;
                GreenBrightness = Y;
                BlueBrightness = 255-Z;
                break;
        }
    }
}




bool digitalLED = true;
bool stripheadlight = false;
uint_16t PEVmaxmmpersecond = 20000;
uint_16t HSVmaxmmpersecondtohuerotation = 6000;
uint_16t HSVminmmpersecondtohuerotation = 500;
if(digitalLED){
  uint_16t LEDpixelcount = 46;
  uint_16t LEDcountpermeter = 60;
}





bool forwardtravel = usefirstLEDbuffer = true;
bool SPIdataready = braking = LEDupdaterequest = firstLEDbufferready = secondLEDbufferready = false;
uint_8t x = SPIstatus = Saturation = Value = 255;
uint_16t y = Hue = MMpersecond = pixelpositionstart = 0;
uint_32t z = uMperLEDrefreshbuffer = uMperLEDrefresh = 0;
uint_16t totalLEDs = 3 * LEDpixelcount;
uint_16t HSVpixelpixeldistanceuM = 1000000 / ( LEDcountpermeter + 1 );//adjust for dead space on both ends of the led strip
uint_16t HSVmaxprepixelcount = HSVmaxmmpersecondtohuerotation / HSVpixelpixeldistanceuM;
uint_16t HSVprehuestep = 65535 / ( HSVmaxprepixelcount + 1 );//adjust so end!=begin number, minor resolution lost
uint_8t Gprecalculated[HSVmaxprepixelcount] = {0};
uint_8t Rprecalculated[HSVmaxprepixelcount] = {0};
uint_8t Bprecalculated[HSVmaxprepixelcount] = {0};
uint_8t firstLEDbuffer[totalLEDs] = {0};
uint_8t secondLEDbuffer[totalLEDs] = {0};
for (i=0; i<=HSVmaxprepixelcount; ++i){
    HSVtoRGB();
    Gprecalculated[i] = GreenBrightness;
    Rprecalculated[i] = RedBrightness;
    Bprecalculated[i] = BlueBrightness;
    Hue += HSVprehuestep;
}
if(digitalLED){
  uint_16t HSVpixelskip = 1;
  uint_16t HSVpixelskipmin = HSVmaxprepixelcount / ( HSVminmmpersecondtohuerotation / HSVpixelpixeldistanceuM );
}

void main(){
  SPIcomms();
  if(SPIstatus==255){//if SPI communication completed
    uMperLEDrefresh = ;//convert data from SPI communication to micrometer per polling cycle, milimeter per second, and direction
    z = ( uMperLEDrefresh * 120 );
    MMpersecond = ( z / 1000 );
    forwardtravel = ;


    while(uMperLEDrefresh>=HSVpixelpixeldistanceuM){//calculate distance traveled to determine new starting pixel
      ++pixelpositionstart;
      if(pixelpositionstart>HSVmaxprepixelcount)
        pixelpositionstart = 0;
      uMperLEDrefresh -= HSVpixelpixeldistanceuM;
    }
    uMperLEDrefreshbuffer += uMperLEDrefresh;
    if(uMperLEDrefreshbuffer>=HSVpixelpixeldistanceuM){
      ++pixelpositionstart;
      if(pixelpositionstart>HSVmaxprepixelcount)
        pixelpositionstart = 0;
      uMperLEDrefreshbuffer -= HSVpixelpixeldistanceuM;
    }


    if(digitalLED){
      if(MMpersecond>=HSVmaxmmpersecondtohuerotation)//calculate precalculated pixel colors to be skipped based on speed
        HSVpixelskip = 1;
      elif(MMpersecond<=HSVminmmpersecondtohuerotation)
        HSVpixelskip = HSVpixelskipmin;
      else
        HSVpixelskip = HSVmaxprepixelcount / ( HSVmaxmmpersecondtohuerotation / HSVpixelpixeldistanceuM );
    }

    SPIdataready = true;
    LEDupdaterequest = true;
  }
  if(LEDupdaterequest){
    if(digitalLED){
      //update headlight
      //update brakelight
      if(SPIdataready){
        if(braking){//update brakelights
          if(forwardtravel)
            bumper2 = 0x00FF00;
          else
            bumper1 = 0x00FF00;
        }else{
          if(forwardtravel)
            bumper2 = 0x000000;
          else
            bumper1 = 0x000000;
        }
        if(stripheadlight){//update headlights
          if(forwardtravel)
            bumper1 = 0xFFFFFF;
          else
            bumper2 = 0xFFFFFF;
        }else{
          if(forwardtravel){
            bumper1 = 0x000000;
            //turn bumper1 headlight pin on
            //turn bumper2 headlight pin off
          }else{
            bumper2 = 0x000000;
            //turn bumper1 headlight pin off
            //turn bumper2 headlight pin on
          }
        }
        y = pixelpositionstart;
        if(usefirstLEDbuffer){
          for (uint_8t i=0; i<=totalLEDs; ++i){
            secondLEDbuffer[i] = Gprecalculated[y];
            ++i;
            secondLEDbuffer[i] = Rprecalculated[y];
            ++i;
            secondLEDbuffer[i] = Bprecalculated[y];
            y += HSVpixelskip;
          }
          secondLEDbufferready = true;
        }else{
          for (uint_8t i=0; i<=totalLEDs; ++i){
            firstLEDbuffer[i] = Gprecalculated[y];
            ++i;
            firstLEDbuffer[i] = Rprecalculated[y];
            ++i;
            firstLEDbuffer[i] = Bprecalculated[y];
            y += HSVpixelskip;
          }
          firstLEDbufferready = true;
        }
      }else{
        if(usefirstLEDbuffer)
          secondLEDbufferready = true;
        else
          firstLEDbufferready = true;
      }
    }else{
      if(braking){
        if(forwardtravel){//update brakelights
          //turn R pins on on bumper2
          //turn GB pins off on bumper2
        }else{
          //turn R pins on on bumper1
          //turn GB pins off on bumper1
        }
      }else{
        if(forwardtravel){
          //turn RGB pins off on bumper2
        }else{
          //turn RGB pins off on bumper1
        }
      }
      if(stripheadlight){//update headlights
        if(forwardtravel)
          //turn RGB pins on on bumper1
        else
          //turn RGB pins on on bumper2
      }else{
        if(forwardtravel){
          //turn RGB pins off on bumper1
          //turn bumper1 headlight pin on
          //turn bumper2 headlight pin off
        }else{
          //turn RGB pins off on bumper2
          //turn bumper1 headlight pin off
          //turn bumper2 headlight pin on
        }
      }
    }
  }
}
