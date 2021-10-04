#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct routing_table *listPt;
typedef struct routing_table{
	int address[4];
	int prefix;
	int decimal;
	listPt link;
};
listPt segmentation_tables1[256]={NULL};
listPt segmentation_tables2[4096]={NULL};
listPt segmentation_tables3[4096]={NULL};
listPt rear1[256]={NULL};
listPt rear2[4096]={NULL};
listPt rear3[4096]={NULL};

void insert(int index, int address[], int pre, int decimal, int num){
	listPt temp = malloc(sizeof(*temp));
	temp->prefix=pre;	temp->decimal=decimal;	temp->link=NULL;
	for(int i=0; i<4; i++)
		temp->address[i]=address[i];
		
	if(num==1){
		if(segmentation_tables1[index] == NULL && rear1[index] == NULL){
			segmentation_tables1[index] = rear1[index] = temp;
			return;
		}
		rear1[index]->link = temp;
		rear1[index] = temp;
	}	
	if(num==2){
		if(segmentation_tables2[index] == NULL && rear2[index] == NULL){
			segmentation_tables2[index] = rear2[index] = temp;
			return;
		}
		rear2[index]->link = temp;
		rear2[index] = temp;
	}
	if(num==3){
		if(segmentation_tables3[index] == NULL && rear3[index] == NULL){
			segmentation_tables3[index] = rear3[index] = temp;
			return;
		}
		rear3[index]->link = temp;
		rear3[index] = temp;
	}
}

void deletion(int index, int address[], int pre, int decimal, int num){
	listPt prev, now;
		
	if(num==1){
		prev = segmentation_tables1[index];
		now = segmentation_tables1[index]->link;
		if(prev->decimal == decimal)
		{
			segmentation_tables1[index]=segmentation_tables1[index]->link;
			free(prev);	return;
		}
		while(now != NULL)
		{
			if(now->decimal == decimal){
				prev->link=now->link;
				free(now);	return;
			}
			prev=prev->link;
			now=now->link;
		}
	}	
	if(num==2){
		prev = segmentation_tables2[index];
		now = segmentation_tables2[index]->link;
		if(prev->decimal == decimal)
		{
			segmentation_tables2[index]=segmentation_tables2[index]->link;
			free(prev);	return;
		}
		while(now != NULL)
		{
			if(now->decimal == decimal){
				prev->link=now->link;
				free(now);	return;
			}
			prev=prev->link;
			now=now->link;
		}
	}
	if(num==3){
		prev = segmentation_tables3[index];
		now = segmentation_tables3[index]->link;
		if(prev->decimal == decimal)
		{
			segmentation_tables3[index]=segmentation_tables3[index]->link;
			free(prev);	return;
		}
		while(now != NULL)
		{
			if(now->decimal == decimal){
				prev->link=now->link;
				free(now);	return;
			}
			prev=prev->link;
			now=now->link;
		}
	}		
}

void search(char search_bi[], int *su_time, int *fa_time){
	listPt temp;
	char ip_bi[32];
	int sea_de=0, ip_de=0;
	int check=0;
	int cal;
	for(int i=0; i<256; i++)
	{
		temp = segmentation_tables1[i];
		while(temp != NULL){
			cal=0;	ip_de=0;	sea_de=0;	
			for(int j=0; j<4; j++){
				for(int k=7; k>=0; k--){
					if( (1<<k) & temp->address[j])
						ip_bi[cal++] = '1';
					else
						ip_bi[cal++] = '0';
				}
			}
			for(int j=0; j<temp->prefix; j++){
				if(ip_bi[j] == '1')
					ip_de = ip_de + (int)1*pow(2,temp->prefix-j-1);
				if(search_bi[j] == '1')
					sea_de = sea_de + (int)1*pow(2,temp->prefix-j-1);
			}
			if(ip_de == sea_de){
				(*su_time)++;	return;
			}
			temp = temp->link;
		}
	}
	
	for(int i=0; i<4096; i++)
	{	
		temp = segmentation_tables2[i];
		while(temp != NULL){
			cal=0;	ip_de=0;	sea_de=0;
			for(int j=0; j<4; j++){
				for(int k=7; k>=0; k--){
					if( (1<<k) & temp->address[j])
						ip_bi[cal++] = '1';
					else
						ip_bi[cal++] = '0';
				}
			}
			for(int j=0; j<temp->prefix; j++){
				if(ip_bi[j] == '1')
					ip_de = ip_de + (int)1*pow(2,temp->prefix-j-1);
				if(search_bi[j] == '1')
					sea_de = sea_de + (int)1*pow(2,temp->prefix-j-1);
			}
			if(ip_de == sea_de){
				(*su_time)++;	return;
			}
			temp = temp->link;
		}
		temp = segmentation_tables3[i];
		while(temp != NULL){
			cal=0;	ip_de=0;	sea_de=0;
			for(int j=0; j<4; j++){
				for(int k=7; k>=0; k--){
					if( (1<<k) & temp->address[j])
						ip_bi[cal++] = '1';
					else
						ip_bi[cal++] = '0';
				}
			}
			for(int j=0; j<temp->prefix; j++){
				if(ip_bi[j] == '1')
					ip_de = ip_de + (int)1*pow(2,temp->prefix-j-1);
				if(search_bi[j] == '1')
					sea_de = sea_de + (int)1*pow(2,temp->prefix-j-1);
			}
			if(ip_de == sea_de){
				(*su_time)++;	return;
			}
			temp = temp->link;
		}
	}
	(*fa_time)++;
}

unsigned long long int begin,end,total=0;		//compute cpu clock
static __inline__ unsigned long long rdtsc(void){
	unsigned hi, lo;
	__asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
	return ( (unsigned long long)lo)|( ((unsigned long long)hi)<<32 );
}

int main(int argc, char *argv[])
{
	char sb[12];
	int cal=0, compare=0, decimal=0, cal_de=0;

	FILE *fpt1, *fpt2, *fpt3, *fpt4, *fpt_out1, *fpt_out2, *fpt_out3;
	fpt1=fopen(argv[1],"r");
	fpt2=fopen(argv[2],"r");
	fpt3=fopen(argv[3],"r");
	fpt4=fopen(argv[4],"r");
	fpt_out1=fopen("insert clock cycles.txt","a");
	fpt_out2=fopen("delete clock cycles.txt","a");
	fpt_out3=fopen("search clock cycles.txt","a");
    int address[4], pre, ip, index=0, check;
	char ch;

	int search_ip, search_deip[4], su_time=0, fa_time=0, cal_sea=0;
	char search_bi[32];

	unsigned long long insert_time, delete_time, search_time;

	while(fscanf(fpt1, "%d%c", &ip, &ch) != EOF)
	{
		address[index++] = ip;
		for(int i=7; i>=0; i--)
		{
			if( (1<<i) & ip && cal_de<=32)
				decimal = decimal +(int)1*pow(2,31-cal_de);
			cal_de++;
	    	if(cal == 12)
	    		break;
			if( (1<<i) & ip ){
				sb[cal++]='1';
				compare = compare + (int)1*pow(2,11-cal+1);
			}
			else
	    		sb[cal++]='0';
		}
		if(ch == '\n')
		{
			pre=ip;
			if(ip<=15)
				insert(address[0]-1, address, pre, decimal, 1);
			else if(ip<=23 && ip>=16)
				insert(compare-1, address, pre, decimal, 2);
			else if(ip<=32 && ip>=24)
				insert(compare-1, address, pre, decimal, 3);
			index=0;
			compare=0;	cal=0;
			decimal=0;	cal_de=0;
		}
	}

	while(fscanf(fpt2, "%d", &search_ip) != EOF)
	{
		cal_sea=0;
		for(int i=31; i>=0; i--)
		{
			if( (1<<i) & search_ip)
				search_bi[cal_sea++] = '1';
			else
				search_bi[cal_sea++] = '0';
		}
		search(search_bi, &su_time, &fa_time);
	}
	printf("After seg. table create\nsuccess search times= %d\nfail search times= %d\n", su_time, fa_time);
	
	while(fscanf(fpt3, "%d%c", &ip, &ch) != EOF)
	{
		address[index++] = ip;
		for(int i=7; i>=0; i--)
		{
			if( (1<<i) & ip && cal_de<=32)
				decimal = decimal +(int)1*pow(2,31-cal_de);
			cal_de++;
	    	if(cal == 12)
	    		break;
			if( (1<<i) & ip ){
				sb[cal++]='1';
				compare = compare + (int)1*pow(2,11-cal+1);
			}
			else
	    		sb[cal++]='0';
		}
		if(ch == '\n')
		{
			pre=ip;
			begin=rdtsc();	//compute cpu cycle
			if(ip<=15)
				insert(address[0]-1, address, pre, decimal, 1);
			else if(ip<=23 && ip>=16)
				insert(compare-1, address, pre, decimal, 2);
			else if(ip<=32 && ip>=24)
				insert(compare-1, address, pre, decimal, 3);
			index=0;
			compare=0;	cal=0;
			decimal=0;	cal_de=0;
			end=rdtsc();					//compute cpu cycle
			total = end - begin;			//compute cpu cycle
			insert_time=insert_time+total;	//compute cpu cycle
			fprintf(fpt_out1, "%d\n", total);
		}
	}

	fpt2=fopen(argv[2],"r");
	su_time=0;	fa_time=0;
	while(fscanf(fpt2, "%d", &search_ip) != EOF)
	{
		cal_sea=0;
		for(int i=31; i>=0; i--)
		{
			if( (1<<i) & search_ip)
				search_bi[cal_sea++] = '1';
			else
				search_bi[cal_sea++] = '0';
		}
		search(search_bi, &su_time, &fa_time);
	}
	printf("\nAfter insertion\navg. insertion time=%d cycles\nsuccess search times= %d\nfail search times= %d\n", \
			insert_time/1000, su_time, fa_time);
	
	while(fscanf(fpt4, "%d%c", &ip, &ch) != EOF)
	{
		address[index++] = ip;
		for(int i=7; i>=0; i--)
		{
			if( (1<<i) & ip && cal_de<=32)
				decimal = decimal +(int)1*pow(2,31-cal_de);
			cal_de++;
	    	if(cal == 12)
	    		break;
			if( (1<<i) & ip ){
				sb[cal++]='1';
				compare = compare + (int)1*pow(2,11-cal+1);
			}
			else
	    		sb[cal++]='0';
		}
		if(ch == '\n')
		{
			pre=ip;
			begin=rdtsc();	//compute cpu cycle
			if(ip<=15)
				deletion(address[0]-1, address, pre, decimal, 1);
			else if(ip<=23 && ip>=16)
				deletion(compare-1, address, pre, decimal, 2);
			else if(ip<=32 && ip>=24)
				deletion(compare-1, address, pre, decimal, 3);
			index=0;
			compare=0;	cal=0;
			decimal=0;	cal_de=0;
			end=rdtsc();					//compute cpu cycle
			total = end - begin;			//compute cpu cycle
			delete_time=delete_time+total;	//compute cpu cycle
			fprintf(fpt_out2, "%d\n", total);
		}
	}

	fpt2=fopen(argv[2],"r");
	su_time=0;	fa_time=0;
	while(fscanf(fpt2, "%d", &search_ip) != EOF)
	{
		cal_sea=0;
		for(int i=31; i>=0; i--)
		{
			if( (1<<i) & search_ip)
				search_bi[cal_sea++] = '1';
			else
				search_bi[cal_sea++] = '0';
		}
		begin=rdtsc();	//compute cpu cycle
		search(search_bi, &su_time, &fa_time);
		end=rdtsc();					//compute cpu cycle
		total = end - begin;			//compute cpu cycle
		search_time=search_time+total;	//compute cpu cycle
		fprintf(fpt_out3, "%d\n", total);
	}
	printf("\nAfter deletion\navg. deletion time=%d cycles\navg. search time=%d cycles\nsuccess search times= %d\nfail search times= %d\n", \
			delete_time/1000, search_time/5080, su_time, fa_time);
	
	fclose(fpt1);
	fclose(fpt2);
	fclose(fpt3);
	fclose(fpt4);
	fclose(fpt_out1);
	fclose(fpt_out2);
	fclose(fpt_out3);
	return 0;
}

