#include "snowman.hpp"
#include <string>
#include <array>
#include <iostream>
namespace ariel
{
  std::string snowman(int input)
  {
    const int eight=8;
    const int five=5;
    const int zero=0;
    const int se=7;
    const int s=6;
    std::string arrnum= std::to_string(input);
    const int x=arrnum.at(se)-'0' - 1;
    const std::array<std::string,4> hat={"_===_","  ___\n .....","   _\n  /_\\","  ___ \n (_*_)"};
    const std::array<std::string,4> nose={",", ".", "_"," "};
    const std::array<std::string,4> eye={".", "o", "O","-"};
    const std::array<std::string,4> torso={" : ", "] [", "> <","   "};
    const std::array<std::string,4> base={" : ", "\" \"", "___","   "};
    const std::array<std::string,4> leftarm={"<","\\","/"," "};
    const std::array<std::string,4> rightArm={">","/","\\"," "};

    for(int i=0;i<eight;i++){
      if((arrnum.at(i)-'0' <=zero) || (arrnum.at(i)-'0' >=five)){
         throw "Error";
      }
    }
    if(arrnum.length() != eight){
      throw "Error";
    }
    /*
        HHHHH
x=2->  X(LNR)Y  <- 2=y
       X(TTT)Y
        (BBB)


      01234567
      HNLRXYTB
    */
  std::string snow=" ";  
  snow+=hat.at(arrnum.at(0)-'0' - 1);
  snow+="\n";
  if( (arrnum.at(4)-'0') == 2 ){
    snow+=leftarm.at(arrnum.at(4)-'0' - 1);
  }
  snow+="(";
  snow+=eye.at(arrnum.at(2)-'0' - 1);
  snow+=nose.at(arrnum.at(1)-'0' - 1);
  snow+=eye.at(arrnum.at(3)-'0' - 1);
  if( (arrnum.at(five)-'0') == 2 )
  {
    snow+=")";
    snow+=rightArm.at(arrnum.at(five)-'0' - 1);
    snow+="\n";
  }
  else
  {
    snow+=")\n";
  }
  if( (arrnum.at(4)-'0') != 2 ){
      snow+=leftarm.at(arrnum.at(4)-'0' - 1);
      snow+="(";
    }
  else
  {
      snow+="(";
    }
  snow+=torso.at(arrnum.at(s)-'0' - 1);
  snow+= ")";
  if(arrnum.at(five)-'0' != 2 ){
    snow+=rightArm.at(arrnum.at(five)-'0' - 1);
  }
  snow+="\n (";
  snow+=base.at(x);
  snow+=")";
  return snow;

  }
}