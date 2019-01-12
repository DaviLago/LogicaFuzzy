#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float cocaForte(float qtd){
	if(qtd < 50)
		return 0;
	if(50 <= qtd && qtd < 52)
		return 1;
	if(52 <= qtd && qtd <= 54)
		return ((54 - qtd)/(54 - 52));
	if(qtd > 54)
		return 0;
	return 0;
}
float cocaSuave(float qtd){
	if(qtd < 52)
		return 0;
	if(52 <= qtd && qtd < 54)
		return ((qtd - 52)/(54 - 52));
	if(54 <= qtd && qtd < 56)
		return 1;
	if(56 <= qtd && qtd <= 58)
		return ((58 - qtd)/(58 - 56));
	if(qtd > 58)
		return 0;
	return 0;
}
float cocaFraca(float qtd){
	if(qtd < 56)
		return 0;
	if(56 <= qtd && qtd < 58)
		return ((qtd - 56)/(56 - 58));
	if(58 <= qtd && qtd <= 60)
		return 1;
	if(qtd > 60)
		return 0;
	return 0;
}

float pepsiForte(float qtd){
	if(qtd < 60)
		return 0;
	if(60 <= qtd && qtd < 62)
		return 1;
	if(62 <= qtd && qtd <= 64)
		return ((64 - qtd)/(64 - 62));
	if(qtd > 64)
		return 0;
	return 0;
}
float pepsiSuave(float qtd){
	if(qtd < 62)
		return 0;
	if(62 <= qtd && qtd < 64)
		return ((qtd - 62)/(64 - 62));
	if(64 <= qtd && qtd < 66)
		return 1;
	if(66 <= qtd && qtd <= 68)
		return ((68 - qtd)/(68 - 66));
	if(qtd > 68)
		return 0;
	return 0;
}
float pepsiFraca(float qtd){
	if(qtd < 66)
		return 0;
	if(66 <= qtd && qtd < 68)
		return ((qtd - 66)/(68 - 66));
	if(68 <= qtd && qtd <= 70)
		return 1;
	if(qtd > 70)
		return 0;
	return 0;
}

float runFraco(float qtd){
	if(qtd < 10)
		return 0;
	if(10 <= qtd && qtd < 15)
		return 1;
	if(15 <= qtd && qtd <= 20)
		return ((20 - qtd)/(20 - 15));
	if(qtd > 20)
		return 0;
	return 0;
}
float runSuave(float qtd){
	if(qtd < 15)
		return 0;
	if(15 <= qtd && qtd < 20)
		return ((qtd - 15)/(20 - 15));
	if(20 <= qtd && qtd < 25)
		return 1;
	if(25 <= qtd && qtd <= 27)
		return ((27 - qtd)/(27 - 25));
	if(qtd > 27)
		return 0;
	return 0;
}
float runForte(float qtd){
	if(qtd < 23)
		return 0;
	if(23 <= qtd && qtd < 28)
		return ((qtd - 23)/(28 - 23));
	if(28 <= qtd && qtd <= 30)
		return 1;
	if(qtd > 30)
		return 0;
	return 0;
}

float gelo(float qtd){
	if(qtd == 20)
		return 1;
	return 0;
}

float min(float refri, float run, float gelo){
	if(refri <= run && refri <= gelo)
		return refri;
	if(run <= refri && run <= gelo)
		return run;
	if(gelo <= refri && gelo <= run)
		return gelo;
	return -1;
}

float media(float min1, float min2, float min3){
	return ((min1 + min2 + min3)/3);
}

float max(float min1, float min2, float min3){
	if(min1 >= min2 && min1 >= min3)
		return min1;
	if(min2 >= min1 && min2 >= min3)
		return min2;
	if(min3 >= min1 && min3 >= min2)
		return min3;
	return -1;
}
float maxPaladar(float suave, float forte, float fraco){
	if(suave > forte && suave > fraco)
		return suave;
	if(forte > suave && forte > fraco)
		return forte;
	if(fraco > suave && fraco > forte)
		return fraco;
	return -1;
}

float calcSuave(float qtdRefri, float qtdRun, float qtdGelo, int refri){
	if(refri == 1)
		return max(min(cocaForte(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaFraca(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));  		
	if(refri == 2)
		return max(min(pepsiForte(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiFraca(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));
	return -1;
}
float calcForte(float qtdRefri, float qtdRun, float qtdGelo, int refri){
	if(refri == 1)
		return max(min(cocaForte(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaForte(qtdRefri), runForte(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));  		
	if(refri == 2)
		return max(min(pepsiForte(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiForte(qtdRefri), runForte(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));
	return -1;
}
float calcFraco(float qtdRefri, float qtdRun, float qtdGelo, int refri){
	if(refri == 1)
		return max(min(cocaFraca(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(cocaFraca(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)));  		
	if(refri == 2)
		return max(min(pepsiFraca(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(pepsiFraca(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)));	  	
	return -1;
}

int main() {
	
	setlocale(LC_ALL,"");
	
	int refri;
	float qtdRefri, qtdRun, qtdGelo;
	float suave, forte, fraco, paladar;
	
	while(1){
		
		printf("Limites:\n");
		printf("  - Coca-Cola:  entre 50 ml e 60 ml\n");
		printf("  - Pepsi-Cola: entre 70 ml e 70 ml\n");
		printf("  - Run:        entre 10 ml e 30 ml\n");
		printf("  - Gelo:       somente 20 ml\n\n");
		
		printf("[1] Coca-Cola [2] Pepsi-Cola: ");
	  	scanf("%d", &refri);
	  	printf("Quantidade de refrigerante em ml: ");
	  	scanf("%f", &qtdRefri);
	  	printf("Quantidade de run em ml: ");
	  	scanf("%f", &qtdRun);
	  	printf("Quantidade de gelo em ml: ");
	  	scanf("%f", &qtdGelo);
	  	  	
	  	suave = calcSuave(qtdRefri, qtdRun, qtdGelo, refri);
	  	forte = calcForte(qtdRefri, qtdRun, qtdGelo, refri);
	  	fraco = calcFraco(qtdRefri, qtdRun, qtdGelo, refri);
		
		paladar = maxPaladar(suave, forte, fraco);
		
		if((paladar == suave && paladar == forte) || (paladar == suave && paladar == fraco) || (paladar == fraco && paladar == forte)){
			if(refri == 1){		
				suave = media(min(cocaForte(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaFraca(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));  		
				forte = media(min(cocaForte(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaForte(qtdRefri), runForte(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));  		
				fraco = media(min(cocaFraca(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(cocaFraca(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(cocaSuave(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)));  		
			}
			else if(refri == 2){
				suave = media(min(pepsiForte(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiFraca(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));
	  			forte = media(min(pepsiForte(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiForte(qtdRefri), runForte(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runForte(qtdRun), gelo(qtdGelo)));
	  			fraco = media(min(pepsiFraca(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)), min(pepsiFraca(qtdRefri), runSuave(qtdRun), gelo(qtdGelo)), min(pepsiSuave(qtdRefri), runFraco(qtdRun), gelo(qtdGelo)));	  	
			}
		}
				
		if((paladar == suave && paladar == forte) || (paladar == suave && paladar == fraco) || (paladar == fraco && paladar == forte))		
			printf("Mesmo tirando a média dos mínimos os valores empataram\n\n");
		
		printf("Grau de pertinência dos paladares:\n");
		printf("  - Suave: %f\n", suave);
		printf("  - Forte: %f\n", forte);
		printf("  - Fraco: %f\n", fraco);
		
		printf("Paladar do drink e preço:\n");
		if(suave == 0 && forte == 0 && fraco == 0){
			printf("  - Nao e Cuba Livre\n");
			printf("Valores inadequados de:\n");
			if(refri == 1 && cocaForte(qtdRefri) == 0 && cocaSuave(qtdRefri) == 0 && cocaFraca(qtdRefri) == 0)
				printf("  - Coca-Cola\n");
			if(refri == 2 && pepsiForte(qtdRefri) == 0 && pepsiSuave(qtdRefri) == 0 && pepsiFraca(qtdRefri) == 0)
				printf("  - Pepsi-Cola\n");
			if(runForte(qtdRun) == 0 && runSuave(qtdRun) == 0 && runFraco(qtdRun) == 0)
				printf("  - Run\n");
			if(gelo(qtdGelo) == 0)
				printf("  - Gelo\n");
		}	
		if(suave == paladar){
			printf("  - Paladar Suave\n");
			printf("  - Valor = R$ 25,00\n\n");
		}
		if(forte == paladar){
			printf("  - Paladar Forte\n");
			printf("  - Valor = R$ 25,00\n\n");
		}
		if(fraco == paladar){
			printf("  - Paladar Fraco\n");
			printf("  - Valor = R$ 15,00\n\n");
		}
		printf("----------------------------------------------------");
		printf("\n\n");
	}
  	
  	return 0;
}

