#include <stdio.h>
int  main()
{
	float n1=0;
	float n2=0;
	float n3=0;
	float MEDIA=0;
	float min=0;
	float max=0;
	
	printf("Inserisci i 3 valori: ");
	scanf("%f%f%f", &n1, &n2, &n3); //i tre valori vanno inseriti con uno spazio l'uno dell'altro

	max=1;
	min=1;
	if (max<n2){
		if(max<n3)
			max=n3;
	}
	else
		if(max<n3)
			max=n3;
	//printf("il massimo è : %f", max);
	if (min>n2){
		min=n2;
			if(min>n3)
				min=n3;
	}
	else
		if(min>n3)
			min=3;
	printf("\nil minimo è: %.2f", min);
    MEDIA=(n1+n2+n3)/3;
    printf("\nla media vale: %.2f",MEDIA);
}                                                                                                                                                                                                                                                                                                                                                                                                                                                       