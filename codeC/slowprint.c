#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

void slowPrint(char* words,int speed){
	while(*words){
		putchar(*words);
		fflush(stdout);
		usleep(speed);
		words++;
	}
	putchar('\n');
}



int main(){
	slowPrint("CY ฿ΰאκЄЯ\n\n",30000);
	slowPrint("⠁⠀⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢠⡄⠀⢀⣼⣿⡄⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢠⣾⣿⣿⣅⢀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠠⣄⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢰⣿⣿⣿⣿⣿⣿⠁⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢺⣷⡄⠀⠀⠀⠀⠀⢠⣶⠾⠃⢀⠀⣠⣦⣿⣿⣿⣿⣿⣿⣿⣿⣇⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣰⣤⠀⠀⠀⠀⠀⠀⢀⣤⣤⡦⠀⠀⠀⠀⠉⣻⣤⣄⠀⠀⠀⠀⠛⠛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⣿⡀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣰⣾⣿⣿⡆⠀⠀⠀⢠⡿⠛⠁⠀⡀⠀⢀⢠⣴⣾⣿⣿⣟⣄⣄⣸⣷⣀⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡏⠁⢻⣿⣤⠀⠂\n"
           "⠀⠀⠀⢤⣴⣾⣽⣶⣠⣦⣴⣿⣟⣌⣿⣥⣿⣴⣢⠉⢷⠀⢠⣼⣷⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⠘⣿⣿⣯⠀\n"
           "⠀⠀⣠⣴⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣾⣿⣏⠻⣆⠀⠀⠀\n"
           "⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣟⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣵⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠂⠘⣿⣿⣿⣯⠀\n"
           "⢀⣿⣿⣿⣿⣿⣿⣿⠋⣔⢾⣿⣷⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢇⢠⣼⣄⠀⠀⠀⠀⠀\n"
           "⠙⠛⣿⣿⣿⣿⣿⣿⣿⣦⡙⣿⢐⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣾⣾⣿⣏⠻⣆⠀⠀⠀\n"
           "⠀⠐⠻⣍⣿⣿⣿⠟⣡⣶⣭⣹⣤⡛⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⢷⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⢹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⢸⣿⣿⣿⠛⠛⡛⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⢷⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⢸⣿⣿⣏⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⢷⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠉⡿⠛⢀⣞⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣧⠈⢷⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⢘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠧⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠀⠀⠀⠀⠀⠀⠀⠈⠀⠈⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
           "⠄⠀⠀⡀⠀⠀⠀⠀⠀⢀⠀⡿⠿⠟⠛⠿⠿⢻⣿⣁⢉⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n",500);

	slowPrint("Ру́сская ку́хня\n — традиционная кухня русского народа.\n Природные особенности мест проживания обширные леса и долгие зимы — обусловили многие характерные особенности традиционной русской кухни: разнообразие горячих супов и каш, квашений и солений, грибных блюд и дичи на русском столе. Центральная роль печи в русской избе предопределила важную роль для домашнего хлеба (кислого ржаного), пирогов и пирожков, томлёных[1], тушёных, варёных и печёных блюд. В традиционной русской кухне, в отличие от современной, использовался один из древнейших способов жаренья, близкий к фритюру — пряжение (обжаривание в толстом, 1—2 см, слое масла)[2].",30000);
	
	return 0;
}