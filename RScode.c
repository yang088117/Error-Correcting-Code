#include <stdio.h>

int a[17],b[17],c[17],d[17],x,y,z,w;
	
int check(int a[],int b[],int c[],int d[])
{
    if(a[15]==0 &&b[15]==0 &&c[15]==0 &&d[15]==0) return -1;
    if(a[15]==1 &&b[15]==0 &&c[15]==0 &&d[15]==0) return 0;
	if(a[15]==0 &&b[15]==1 &&c[15]==0 &&d[15]==0) return 1;
	if(a[15]==0 &&b[15]==0 &&c[15]==1 &&d[15]==0) return 2;
	if(a[15]==0 &&b[15]==0 &&c[15]==0 &&d[15]==1) return 3;
	if(a[15]==1 &&b[15]==1 &&c[15]==0 &&d[15]==0) return 4;
	if(a[15]==0 &&b[15]==1 &&c[15]==1 &&d[15]==0) return 5;
	if(a[15]==0 &&b[15]==0 &&c[15]==1 &&d[15]==1) return 6;
	if(a[15]==1 &&b[15]==1 &&c[15]==0 &&d[15]==1) return 7;
	if(a[15]==1 &&b[15]==0 &&c[15]==1 &&d[15]==0) return 8;
	if(a[15]==0 &&b[15]==1 &&c[15]==0 &&d[15]==1) return 9;
	if(a[15]==1 &&b[15]==1 &&c[15]==1 &&d[15]==0) return 10;
	if(a[15]==0 &&b[15]==1 &&c[15]==1 &&d[15]==1) return 11;
	if(a[15]==1 &&b[15]==1 &&c[15]==1 &&d[15]==1) return 12;
	if(a[15]==1 &&b[15]==0 &&c[15]==1 &&d[15]==1) return 13;
	if(a[15]==1 &&b[15]==0 &&c[15]==0 &&d[15]==1) return 14;
	

}

int multi(int x,int y,int z)
{
    if(x==-1||y==-1||z==-1)
    return -1;
    else
    {
	int m;
	m=(x+y+z)%15;
	return m;
    }
}

int plus(int x,int y)
{
	a[15]=(a[x]+a[y])%2 ,b[15]=(b[x]+b[y])%2,c[15]=(c[x]+c[y])%2 ,d[15]=(d[x]+d[y])%2;
	return check(a,b,c,d);
}

int divi(int x,int y)
{
	if(x==-1||y==-1) return -1;
	else if(x>y) return x-y; 
	else return (15+x-y)%15;
}

void polydivi(int pl1[],int pl2[],int pl3[],int pl4[],int pl5[])//pl1[]���Q���� pl2[]������ pl3[] pl4[]���� pl5[]���l��  
{
	int i,n2=0,n1=0,de=0;
	for(i=7;i>=0;i--)//��X�����̰��� 
	{
		if(pl2[i]!=-1)
		{
			n2=i; 
			break;
		}
	}
	for(i=7;i>=0;i--)//��X�Q�����̰��� 
	{
		if(pl1[i]!=-1)
		{
			n1=i; 
			break;
		}
	}
	//n1���Q�����̰���   n�������̰��� 
	de=n1-n2;//��X�Q�����P�����t�X�� 
	
	
    if(n1>=n2)
	{
		
		
		for(i=n2;i>=0;i--)
	    {
		   pl3[i+de]=multi(pl2[i],multi(divi(0,pl2[n2]),pl1[n1],0),0);//�o��@�� pl3���� �� pl1�����@�� 
	    }
		int p=pl1[n1];
	    for (i = 0; i <= 7; i++) {
            pl5[i] = plus(pl1[i],pl3[i]);
        }
        //�o��pl5[]���l�� �P�ɤ]�O�Q���� 
	    pl4[de]=multi(divi(0,pl2[n2]),p,0);//�o��}�l��J�� 
	    
		int pl6[8];
	    for(i=0;i<8;i++)
	    {
	    	pl6[i]=-1;
		}
	    polydivi(pl5,pl2,pl6,pl4,pl5);//pl2���ʩT�w������  pl5���Q����  pl3�n�����M�ũҥH��pl6���M�v�T����p��  
	}
}


void polymulti(int pl1[],int pl2[],int pl3[])
{
	pl3[0]=multi(pl1[0],pl2[0],0);
	pl3[1]=plus(multi(pl1[0],pl2[1],0),multi(pl1[1],pl2[0],0));
	pl3[2]=plus(plus(multi(pl1[0],pl2[2],0),multi(pl1[1],pl2[1],0)),multi(pl1[2],pl2[0],0));
	pl3[3]=plus(plus(plus(multi(pl1[0],pl2[3],0),multi(pl1[1],pl2[2],0)),multi(pl1[2],pl2[1],0)),multi(pl1[3],pl2[0],0));
	pl3[4]=plus(plus(multi(pl1[1],pl2[3],0),multi(pl1[2],pl2[2],0)),multi(pl1[3],pl2[1],0));
	pl3[5]=plus(multi(pl1[2],pl2[3],0),multi(pl1[3],pl2[2],0));
	pl3[6]=multi(pl1[3],pl2[3],0);
}






void bubble(int a[],int n) 
{
	int i,j,t;
	for(i=n-1;i>0;i--) 
	{
		for(j=0;j<i;j++)
		{
			if(a[j]>a[j+1])
			{
			    t=a[j];
			    a[j]=a[j+1];
			    a[j+1]=t;
		    }
		}
	}
}







void printpoly(int result[])
{
	if(result[0]==0)
	    printf("1 ");
	else if(result[0]>0)
	    printf("a^%d ",result[0]);
	for(int i=1;i<15;i++) 
	{
		if(result[i]!=-1)
		    printf("+ a^%dX^%d ",result[i],i);
	}
	if(result[0]==-1&&result[1]==-1&&result[2]==-1&&result[3]==-1&&result[4]==-1&&result[5]==-1&&result[6]==-1&&result[7]==-1&&result[8]==-1&&result[9]==-1&&result[10]==-1&&result[11]==-1&&result[12]==-1&&result[13]==-1&&result[14]==-1)
	{
		printf("0 ");
	}
}








int main() {
	 a[0]=1;b[0]=0;c[0]=0;d[0]=0;
	 a[1]=0;b[1]=1;c[1]=0;d[1]=0;
	 a[2]=0;b[2]=0;c[2]=1;d[2]=0;
	 a[3]=0;b[3]=0;c[3]=0;d[3]=1;
	 a[4]=1;b[4]=1;c[4]=0;d[4]=0;
	 a[5]=0;b[5]=1;c[5]=1;d[5]=0;
	 a[6]=0;b[6]=0;c[6]=1;d[6]=1;
	 a[7]=1;b[7]=1;c[7]=0;d[7]=1;
	 a[8]=1;b[8]=0;c[8]=1;d[8]=0;
	 a[9]=0;b[9]=1;c[9]=0;d[9]=1;
	 a[10]=1;b[10]=1;c[10]=1;d[10]=0;
	 a[11]=0;b[11]=1;c[11]=1;d[11]=1;
	 a[12]=1;b[12]=1;c[12]=1;d[12]=1;
	 a[13]=1;b[13]=0;c[13]=1;d[13]=1;
	 a[14]=1;b[14]=0;c[14]=0;d[14]=1;
	 a[15]=0,b[15]=0,c[15]=0,d[15]=0;
	 

	int i=0,j,v[15]={0},o[15]={0},s[15];
	for(i=0;i<15;i++)//�OO(i)������-1�o�ܭ��n����R 
	{
		o[i]=-1;
	}
	printf("(15,9)RS code\n");
	printf("�p�GR(x)��x���s����x���̥|�����Y�ƽж� 1 �Ϥ��� 0 \n");
	printf("\n");
    
		
	for(i=0;i<15;i++)
	{
		printf("x��%d����:",i);
		scanf("%d",&v[i]);//�Y�� 
	}
	for(i=0;i<15;i++)
	{
		if(v[i]==0)
		{
			v[i]=-1;			 
		} 
		
	}
	printf("\n\n�`�N:�p�G�Y�Ƭ� 1 �]�N�Oalpha���s�� �O�o��s\n\n");	    
	for(i=0;i<15;i++)
	{
		if(v[i]==1)
		{
			printf("x^%d��alpha�������:",i);
		    scanf("%d",&v[i]);//�Y��
						 
		} 
		
	}
	printf("\n�����쪺�h����R(x)= ");
	printpoly(v);
	printf("\n");	
		 
		
    
	for(j=1;j<7;j++)//���k1����6����J�� r(x) �D s 
	{
		int sum=-1;
		for(i=0;i<15;i++)
		{
			if(v[i]>=0)
			o[i]=(v[i]+j*i)%15;
		} 
		for(i=0;i<15;i++)
		{
			if(o[i]>=0)
			{
				sum=plus(plus(o[i],-1),sum);
			}
		}
		s[j]=sum;
	}
	printf("\n�H�U�Ʀr�Ҭ�alpha������� -1�N��S���t��\ns1��s6����: ");
	for(i=1;i<7;i++)
    printf("s[%d]=%d ",i,s[i]);	
	
	printf("\n");
	
	int resig[8],pl1[8],pl2[8],pl3[8],pl4[8],pl5[8],omaga1[8],qm1[8],omaga2[8],qm2[8],omaga3[8],qm3[8],sigma[15],o1[15];//pl1���Q����  pl2������  pl3  pl4����  pl5���l�� 
	for(i=0;i<8;i++)
	{
		pl1[i]=-1;
		pl2[i]=-1;
		pl3[i]=-1;
		pl4[i]=-1;
		pl5[i]=-1;
		omaga1[i]=-1;
		qm1[i]=-1;
		omaga2[i]=-1;
		qm2[i]=-1;
		omaga3[i]=-1;
		qm3[i]=-1;
		resig[i]=-1;
		
	}
	
	
	
	for(i=0;i<15;i++)
	{
		sigma[i]=-1;
		o[i]=-1;
	}
	
	
	
	
	
	pl1[7]=0;//��X^7 
	for(i=1;i<=6;i++)
	{
		int f=i;
		pl2[i]=s[f];
	}
	
	pl2[0]=0;//S(x)+1
	polydivi(pl1,pl2,pl3,pl4,pl5);//pl1�Q����pl2����pl3�Ȧs�Ŷ� pl4�� pl5�l�� 
	 //���� pl3 pl4 pl5   ������ pl1 pl2 
	//pl4�� pl5�l ���n���ள�h��   pl3�Ȧs�Ŷ������n
	for(i=0;i<8;i++)
	{
		qm1[i]=pl4[i];
		omaga1[i]=pl5[i];
	}
	



    printf("\n\n�B��L�{\n\n------------------------------------------------\n\n");

        for(i=0;i<=7;i++) 
	    {
			if(qm1[i]!=-1)
		    printf("sigma1[%d]=%d ",i,qm1[i]);
	    }
	    printf("\n");
		for(i=0;i<=7;i++)
	    {
			if(omaga1[i]!=-1)
            printf("omaga1[%d]=%d ",i,omaga1[i]);
	    }
	    printf("\n------------------------------------------------\n\n");










	
	int n,checkomaga;//�p��omaga����ƬO�_�j��p�� 3 
	for(i=7;i>=0;i--)
	{
		if(omaga1[i]!=-1)
		{
			n=i;
			break;
		}
	}
	
	
	checkomaga=1;
	
	
	if(n>3)
	{
		for(i=0;i<8;i++)
	    {
		    pl3[i]=-1;
		    pl1[i]=-1;
		    pl4[i]=-1; 
	    } 
	    polydivi(pl2,pl5,pl3,pl1,pl4);
	
	
	
	    for(i=0;i<8;i++)
	    {
		    qm2[i]=pl1[i];
		    omaga2[i]=pl4[i];
	    }


        for(i=0;i<=7;i++) 
	    {
			if(qm2[i]!=-1)
		    printf("sigma2[%d]=%d ",i,qm2[i]);
	    }
	    printf("\n");
		for(i=0;i<=7;i++)
	    {
			if(omaga2[i]!=-1)
            printf("omaga2[%d]=%d ",i,omaga2[i]);
	    }
	    printf("\n------------------------------------------------\n\n");





	    for(i=7;i>=0;i--)
	    {
		if(omaga2[i]!=-1)
		{
			n=i;
			break;
		}
	    }
	   
	    checkomaga=2;
	}
	
	
	
	if(n>3)
	{
		for(i=0;i<8;i++)
	    {
		   pl2[i]=-1;
		   pl1[i]=-1;
		   pl3[i]=-1; 
	    }
	    polydivi(omaga1,pl4,pl3,pl1,pl2);
	
	
	    for(i=0;i<8;i++)
	    {
		    qm3[i]=pl1[i];
		    omaga3[i]=pl2[i];
	    }
	    checkomaga=3;
	    
	    
	}
	 
	 
	
	
		polymulti(qm1,qm2,resig);
	
	    resig[0]=plus(resig[0],0); 
	    
	
	
	    for(i=7;i>=0;i--)
	    {
	    	pl3[i]=-1;
	    }
	
	    polymulti(qm3,resig,pl3);
	    
	
	
	    for(i=7;i>=0;i--)
	    {
	    	pl3[i]=plus(qm1[i],pl3[i]);
	    }
	    
        	
	if(checkomaga==3)
	{
		
		for(i=7;i>=0;i--)
		{
			omaga3[i]=divi(omaga3[i],omaga3[0]);
			pl3[i]=divi(pl3[i],pl3[0]);
		}
		
		
		
		for(i=0;i<=7;i++) 
	    {
			if(pl3[i]!=-1)
		    printf("sigma[%d]=%d ",i,pl3[i]);
	    }
	    printf("\n");
		for(i=0;i<=7;i++)
	    {
			if(omaga3[i]!=-1)
            printf("omaga[%d]=%d ",i,omaga3[i]);
	    }
	    printf("\n------------------------------------------------\n\n");
		

		
	    int i1=0;
	    for(j=0;j<15;j++)
	    {
	    	int sum=-1;
		    for(i=0;i<8;i++)
		    {
			   if(pl3[i]>=0)
			   o[i]=(pl3[i]+j*i)%15;
		    } 
		    for(i=0;i<8;i++)
		    {
			   if(o[i]>=0)
			   {
			       sum=plus(plus(o[i],-1),sum);
			   }
			}
		    if(sum==-1)
		    {
		    	sigma[i1]=j;
		    	i1++;
			}
		    

		}
		
	    for(i=0;i<15;i++)
	    {
	    	if(sigma[i]!=-1)
	    	sigma[i]=divi(0,sigma[i]);
		}
	    bubble(sigma,3);
	    printf("\n���~��m\n\n");
	    for(i=0;i<3;i++)
	    {
			if(sigma[i]!=-1)
	    	printf("X^%d\n",sigma[i]);
		}
		
	    int ej[3];
	    for(i=0;i<3;i++)
	    {
	    	ej[i]=-1;
		}
	    for(j=0;j<3;j++)
	    {
	    	int sum=-1;
	    	for(i=0;i<8;i++)
	        {
	        	sum=plus(multi(omaga3[i],i*divi(0,sigma[j]),0),sum);
			}
			ej[j]=sum;
		}
		
	    
	    ej[0]=divi(ej[0],multi(plus(0,multi(divi(0,sigma[0]),sigma[1],0)),plus(0,multi(divi(0,sigma[0]),sigma[2],0)),0));    
	    ej[1]=divi(ej[1],multi(plus(0,multi(divi(0,sigma[1]),sigma[0],0)),plus(0,multi(divi(0,sigma[1]),sigma[2],0)),0));    
	    ej[2]=divi(ej[2],multi(plus(0,multi(divi(0,sigma[2]),sigma[1],0)),plus(0,multi(divi(0,sigma[2]),sigma[0],0)),0));
	    printf("\n\n���~��\n\n");
		for(i=0;i<3;i++)
	    {
	    	if(sigma[i]!=-1)
	    	printf("ej(%d)=%d\n",sigma[i],ej[i]); 
		}
		int e[15],result[15];
	    for(i=0;i<15;i++)
	    {
	    	e[i]=-1;
	    	result[i]=-1;
		}
		for(i=0;i<3;i++)
	    e[sigma[i]]=ej[i];
	    
		for(i=0;i<15;i++) 
	    {
	    	result[i]=plus(v[i],e[i]);
		}
		




		printf("\n\nr(x) = ");
		printpoly(v);
		printf("\n");
		printf("e(x) = ");
		printpoly(e);
		printf("\n");
		printf("c(x) = r(x) + e(x)");
		








		printf("\n\n�ѽX�᪺�h����C(x) = ");
		printpoly(result);
	}
	else if(checkomaga==2)
	{
		
		for(i=7;i>=0;i--)
		{
			omaga2[i]=divi(omaga2[i],omaga2[0]);
			resig[i]=divi(resig[i],resig[0]);
		}
		for(i=0;i<=7;i++) 
	    {
			if(resig[i]!=-1)
		    printf("sigma[%d]=%d ",i,resig[i]);
	    }
	    printf("\n");
		for(i=0;i<=7;i++)
	    {
			if(omaga2[i]!=-1)
            printf("omaga[%d]=%d ",i,omaga2[i]);
	    }
	    printf("\n------------------------------------------------\n\n");



	    int i1=0;
	    for(j=0;j<15;j++)
	    {
	    	int sum=-1;
		    for(i=0;i<8;i++)
		    {
			   if(resig[i]>=0)
			   o[i]=(resig[i]+j*i)%15;
		    } 
		    for(i=0;i<8;i++)
		    {
			   if(o[i]>=0)
			   {
			       sum=plus(plus(o[i],-1),sum);
			   }
			}
		    if(sum==-1)
		    {
		    	sigma[i1]=j;
		    	i1++;
			}
		    

		}
		
	    for(i=0;i<15;i++)
	    {
	    	if(sigma[i]!=-1)
	    	sigma[i]=divi(0,sigma[i]);
		}
	    bubble(sigma,3);
	    printf("\n\n���~��m\n\n");
	    for(i=0;i<3;i++)
	    {
			if(sigma[i]!=-1)
	    	printf("X^%d\n",sigma[i]);
		}
		
	    int ej[3];
	    for(i=0;i<3;i++)
	    {
	    	ej[i]=-1;
		}
	    for(j=0;j<3;j++)
	    {
	    	int sum=-1;
	    	for(i=0;i<8;i++)
	        {
	        	sum=plus(multi(omaga2[i],i*divi(0,sigma[j]),0),sum);
			}
			ej[j]=sum;
		}
		
	    
	    ej[0]=divi(ej[0],multi(plus(0,multi(divi(0,sigma[0]),sigma[1],0)),plus(0,multi(divi(0,sigma[0]),sigma[2],0)),0));    
	    ej[1]=divi(ej[1],multi(plus(0,multi(divi(0,sigma[1]),sigma[0],0)),plus(0,multi(divi(0,sigma[1]),sigma[2],0)),0));    
	    ej[2]=divi(ej[2],multi(plus(0,multi(divi(0,sigma[2]),sigma[1],0)),plus(0,multi(divi(0,sigma[2]),sigma[0],0)),0));
	    printf("\n\n���~��\n\n");
		for(i=0;i<3;i++)
	    {
	    	if(sigma[i]!=-1)
	    	printf("ej(%d)=%d\n",sigma[i],ej[i]);
		}
		int e[15],result[15];
	    for(i=0;i<15;i++)
	    {
	    	e[i]=-1;
	    	result[i]=-1;
		}
		for(i=0;i<3;i++)
	    e[sigma[i]]=ej[i];
	    
		for(i=0;i<15;i++) 
	    {
	    	result[i]=plus(v[i],e[i]);
		}




		printf("\n\nr(x) = ");
		printpoly(v);
		printf("\n");
		printf("e(x) = ");
		printpoly(e);
		printf("\n");
		printf("c(x) = r(x) + e(x)");
		



		printf("\n\n�ѽX�᪺�h����C(x) = ");
		printpoly(result);
	}
	else if(checkomaga==1)
	{
		
		for(i=7;i>=0;i--)
		{
			omaga1[i]=divi(omaga1[i],omaga1[0]);
			qm1[i]=divi(qm1[i],qm1[0]);
		}
        
        
        for(i=0;i<=7;i++) 
	    {
			if(qm1[i]!=-1)
		    printf("sigma[%d]=%d ",i,qm1[i]);
	    }
	    printf("\n");
		for(i=0;i<=7;i++)
	    {
			if(omaga1[i]!=-1)
            printf("omaga[%d]=%d ",i,omaga1[i]);
	    }
	    printf("\n------------------------------------------------\n\n");
        
        
	    
		int i1=0;
	    for(j=0;j<15;j++)
	    {
	    	int sum=-1;
		    for(i=0;i<8;i++)
		    {
			   if(qm1[i]>=0)
			   o[i]=(qm1[i]+j*i)%15;
		    } 
		    for(i=0;i<8;i++)
		    {
			   if(o[i]>=0)
			   {
			       sum=plus(plus(o[i],-1),sum);
			   }
			}
		    if(sum==-1)
		    {
		    	sigma[i1]=j;
		    	i1++;
			}
		    

		}
		
	    for(i=0;i<15;i++)
	    {
	    	if(sigma[i]!=-1)
	    	sigma[i]=divi(0,sigma[i]);
		}
	    bubble(sigma,3);
	    printf("\n\n���~��m\n\n");
	    for(i=0;i<3;i++)
	    {
			if(sigma[i]!=-1)
	    	printf("X^%d\n",sigma[i]);
		}
		
	    int ej[3];
	    for(i=0;i<3;i++)
	    {
	    	ej[i]=-1;
		}
	    for(j=0;j<3;j++)
	    {
	    	int sum=-1;
	    	for(i=0;i<8;i++)
	        {
	        	sum=plus(multi(omaga1[i],i*divi(0,sigma[j]),0),sum);
			}
			ej[j]=sum;
		}
		
	    
	    ej[0]=divi(ej[0],multi(plus(0,multi(divi(0,sigma[0]),sigma[1],0)),plus(0,multi(divi(0,sigma[0]),sigma[2],0)),0));    
	    ej[1]=divi(ej[1],multi(plus(0,multi(divi(0,sigma[1]),sigma[0],0)),plus(0,multi(divi(0,sigma[1]),sigma[2],0)),0));    
	    ej[2]=divi(ej[2],multi(plus(0,multi(divi(0,sigma[2]),sigma[1],0)),plus(0,multi(divi(0,sigma[2]),sigma[0],0)),0));
	    printf("\n\n���~��\n\n");
		for(i=0;i<3;i++)
	    {
	    	if(sigma[i]!=-1)
	    	printf("ej(%d)=%d\n",sigma[i],ej[i]);
		}
		int e[15],result[15];
	    for(i=0;i<15;i++)
	    {
	    	e[i]=-1;
	    	result[i]=-1;
		}
		for(i=0;i<3;i++)
	    e[sigma[i]]=ej[i];
	    

		
		for(i=0;i<15;i++) 
	    {
	    	result[i]=plus(v[i],e[i]);
		}






		printf("\n\nr(x) = ");
		printpoly(v);
		printf("\n");
		printf("e(x) = ");
		printpoly(e);
		printf("\n");
		printf("c(x) = r(x) + e(x)");
		
		


		printf("\n\n�ѽX�᪺�h����C(x) = ");
		printpoly(result);
	}
	   printf("\n\n");
	return 0;
}