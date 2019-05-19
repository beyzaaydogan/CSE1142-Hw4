#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//const int SIZE = 10;
#define SIZE 10

typedef struct {
		char name[20];
		double x,y;
}MetroStation;


typedef struct {
	char color[20];
	MetroStation MetroStations[SIZE];	

}MetroLine;


typedef struct {
	char name[20];
	MetroLine MetroLines[SIZE];

}MetroSystem;



int equals(MetroStation s1, MetroStation s2){

	if( s1.name == s2.name)
		return 1;
	else
		return 0;
}

void addStation(MetroLine* ml , MetroStation ms){
 		for(int i=0;i<SIZE;i++){
 			if(ml->MetroStations[i].name[1] ==  '\0'){
 				strcpy(ml->MetroStations[i].name,ms.name);
 				memcpy(&(ml->MetroStations[i].x),&ms.x,8);
 				memcpy(&(ml->MetroStations[i].y),&ms.y,8);
 				printf("inside addStation %.2f \n",ml->MetroStations[i].x);
 				break;
 			}
 		}
		
}

int hasStation(MetroLine ml, MetroStation ms){
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
 			if(strcmp((ml.MetroStations[i]).name,ms.name)==0){
 				printf("%s\n","hello" );
 				return 1;
 			}
 			else{
 			//	printf("%s\n","dear lord" );
 				return 0;
 			}
}
}
}
MetroStation getFirstStop(MetroLine ml){
	if(ml.MetroStations[0].name != NULL)
	return ml.MetroStations[0];
	else {
		MetroStation ms;
		return ms;
	}

}
MetroStation getPriorStop(MetroLine ml,MetroStation ms){
	for(int i=0;i<SIZE;i++){
 		//if((ml.MetroStations[i]).name ==  ms.name){
 		if(strcmp((ml.MetroStations[i]).name,ms.name)==0){
 			printf(" names %s %s\n",(ml.MetroStations[i]).name,ms.name );
			return ml.MetroStations[i-1];}
		if(strcmp((ml.MetroStations[i]).name,ms.name)==0&& i==0){
			printf("inside 0" );
			MetroStation ms;
			return ms;

			}

	}
}

MetroStation getNextStop(MetroLine ml,MetroStation ms){
	for(int i=0;i<SIZE;i++){
 		//if((ml.MetroStations[i]).name ==  ms.name){
 		if(strcmp((ml.MetroStations[i]).name,ms.name)==0){
 			printf("inside not zero case \n" );
 			printf(" names %s %s\n",(ml.MetroStations[i]).name,ms.name );
			return ml.MetroStations[i+1];}
		if(strcmp((ml.MetroStations[i]).name,ms.name)==0&& i==SIZE-1){
			printf("inside 0" );
			MetroStation ms;
			return ms;

			}

	}
}
void addLine(MetroSystem* ms, MetroLine ml ){
	MetroLine control[2]={'\0','\0'} ;
	for(int i=0;i<SIZE;i++){
	 	if((ms->MetroLines[i]).color[0] == control[0].color[0]){
	printf("addLine color is: %s\n",&ml.color[0] );
	 		
	 	/*	strcpy(ms->MetroLines[i].color, ml.color);
	 		strcpy(ms->MetroLines[i].MetroStations->name, ml.MetroStations->name);
	 		ms->MetroLines[i].MetroStations->x=ml.MetroStations->x;
	 		ms->MetroLines[i].MetroStations->y=ml.MetroStations->y;
	 	//	&ms->MetroLines[i]= malloc(380);*/
	 		memcpy(&((*ms).MetroLines[i]),&ml,380);
	 		break;
	 	//	printf("color %s\n",&(ms->MetroLines[i]).color[0] );
		}
	}
}
void printLine(MetroLine ml){
	printf("MetroLine %s: ", ml.color);
	for(int i=0;i<SIZE;i++){
		printf(" %s " ,(ml.MetroStations[i]).name);
	}

}
void printPath(MetroStation ms[]){
	for(int i=0;i<SIZE;i++){
		printf("%s\n",ms[i].name);
		}
}
float getDistanceTravelled(MetroStation ms[] ){
		float distance=0.0;		
		for(int i=1;i<SIZE;i++){
			if(ms[i].x != 0){
			printf("x>>> %.2f\n", ms[i].x);	
			printf("y>>> %.2f\n", ms[i].y);	
			printf("pow x %.2f\n",pow(ms[i].x-ms[i-1].x,2) );
			printf("pow y %.2f\n",pow(ms[i].y-ms[i-1].y,2) );

			printf("distance: %.2f\n",sqrt(pow(ms[i].x-ms[i-1].x,2)+pow(ms[i].y-ms[i-1].y,2)*1.0) );	
			distance += sqrt(pow(ms[i].x-ms[i-1].x,2)+pow(ms[i].y-ms[i-1].y,2)*1.0);
			}

		}
		return distance;
}

MetroStation findNearestStation(MetroSystem ms,double x,double y){
	double first, next, x2, y2 ;
	MetroStation tempStation =  ms.MetroLines[0].MetroStations[0];
	
	 x2= ms.MetroLines[0].MetroStations[0].x;
	 y2= ms.MetroLines[0].MetroStations[0].y;			
	 first= sqrt(pow(x2-x,2)+pow(y2-y,2)*1.0);
	for(int i=0;i<SIZE;i++){
		for(int j=0;j<SIZE;j++){
			x2= ms.MetroLines[i].MetroStations[j].x;
	 		y2= ms.MetroLines[i].MetroStations[j].y;		
			next = sqrt(pow(x2-x,2)+pow(y2-y,2)*1.0);
			if(next<first){
				first = next;
				tempStation= ms.MetroLines[i].MetroStations[j];
			}
	}
			
}
	return tempStation;
}

void getNeighboringStations(MetroSystem mSystem,MetroStation mStation,MetroStation neighboringStations[]){
	int k=0;
	for(int i=0;i<SIZE;i++){	
		for(int j=0;j<SIZE;j++){
			if(strcmp(mSystem.MetroLines[i].MetroStations[j].name,mStation.name)==0){
				memcpy(&neighboringStations[k],&mSystem.MetroLines[i].MetroStations[j+1],36);
				if(j !=0){
				memcpy(&neighboringStations[k+1],&mSystem.MetroLines[i].MetroStations[j-1],36);
				k++;	
				}
				
			k++;

			}
		}
	}
}



int main(){
	int i;
	double myX=1, myY=2; 
	double goalX=62, goalY=45; 
MetroSystem istanbul = {"istanbul", '\0'};
MetroLine red={'\0'}, blue={'\0'}, green={'\0'};
MetroStation s1,s2,s3,s4, s5, s6, s7, s8, s9;
MetroStation myPath[SIZE]={'\0'};

strcpy(red.color, "red");
strcpy(blue.color, "blue");
strcpy(green.color, "green");
strcpy(s1.name, "Haydarpasa"); 		s1.x=0; 	s1.y=0; 	
strcpy(s2.name, "Sogutlucesme"); 	s2.x=10; 	s2.y=5;
strcpy(s3.name, "Goztepe"); 		s3.x=20; 	s3.y=10;
strcpy(s4.name, "Kozyatagi"); 		s4.x=30; 	s4.y=35;
strcpy(s5.name, "Bostanci"); 		s5.x=45; 	s5.y=20;
strcpy(s6.name, "Kartal"); 			s6.x=55; 	s6.y=20;
strcpy(s7.name, "Samandira"); 		s7.x=60; 	s7.y=40;
strcpy(s8.name, "Icmeler"); 		s8.x=70; 	s8.y=15;

addStation(&red, s1); addStation(&red, s2); addStation(&red, s3);
addStation(&blue, s2); addStation(&blue, s3); addStation(&blue, s4); addStation(&blue, s6); addStation(&blue, s7);
addStation(&green, s2); addStation(&green, s3); addStation(&green, s5); addStation(&green, s6); addStation(&green, s8);
MetroStation myPath1[SIZE]={s1,s2,s3,s4};
MetroStation neighbors[SIZE]={'\0'};

printf("Metro Line is  %s %s %s\n",(red.MetroStations)->name,(red.MetroStations[1]).name,(red.MetroStations[2]).name);
printf("s1 : %s\n", s1.name);
printf("hasStation:  %d\n",hasStation(red,s1) );
printf("getFirstStop: %s\n",getFirstStop(red).name);
printf("getPriorStop: %s\n",getPriorStop(red,s3).name);
addLine(&istanbul,red);
addLine(&istanbul, blue);
addLine(&istanbul, green);
printf("addLine: %s\n",&(istanbul.MetroLines[0]).color[0]);
printf("printLine ");
printLine(blue);
printf("\n%s\n","printPath" );
printPath(myPath1);
printf("name %s\n",myPath1[0].name );
printf("getDistanceTravelled: %.2f \n",getDistanceTravelled(myPath1) );
printf("%s %s\n","myx myy nearest station is ",findNearestStation(istanbul, myX, myY).name);
printf("goalx goaly  %s\n",findNearestStation(istanbul, goalX, goalY).name ); 
printf("%s\n","getNeighboringStations" );
getNeighboringStations(istanbul,s6,neighbors);
printf("%s %s %s %s \n",neighbors[0].name,neighbors[1].name,neighbors[2].name ,neighbors[3].name);
}