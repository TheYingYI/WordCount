#include <stdio.h>

int main(int argc, char **argv){
    int ch_count = 0;
    int word_count = 0;
    char ch1;
    char all_word[10000]="";
    int i = 0;
    int flag = 0;

    
    FILE *fp = fopen(argv[2],"r");
    if(fp==NULL){
        printf("open file failed.\n");              //打开文本 
    }

	 while(1)
   {
      ch1 = fgetc(fp);
      if( feof(fp) )
      {
          break ;
      }
      all_word[i] = ch1;
                          //  读取文本内容 
      i++;
   }
    int ch_num=i;
    fclose(fp);
	
    
    int j=0;
    while(1){
    	 if(all_word[j] == '\0'){
    	 	break;
		 }
         if(all_word[j]==' '|| all_word[j]==','){
            flag = 0;
        }



        if(all_word[j]==' '|| all_word[j]=='\t'|| all_word[j]==','){
            
        }else{
            if(flag==0){
            	flag=1;
                while(1){
                    if(all_word[j]=='\0'){
                        break;
                    }
                	if(all_word[j+1]==' '||all_word[j+1]==','){
                		break;
					}
	
					j++;
                }
                j--;
                word_count++;
            }
            
        }
        j++;
    }

    
    if(argv[1][1]=='c'|| argv[1][1]=='C'){
        printf("字符数: %d",ch_num);
    }
    else if(argv[1][1]=='w'||argv[1][1]=='W'){
        printf("单词数: %d",word_count);
    }
    

    return 0;
}
