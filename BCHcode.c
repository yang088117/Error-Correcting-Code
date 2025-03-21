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
	 

	int i=0,j,v[15]={0},o[15],s[7];
	printf("(15,5)BCH code\n");
	printf("請輸入R(x)由x的零次到十四次的係數 0 or 1 \n");
	printf("\n");
    
		
	for(i=0;i<15;i++)
	{
		printf("x的%d次方之係數:",i);
		scanf("%d",&v[i]);//係數 
	}	    
		
		 
		
	printf("\n");
	for(j=1;j<7;j++)//阿法1次到6次輸入到 r(x) 求 s 
	{
		
		for(i=1;i<15;i++)
		{ 
		    if(v[i]==0) 
			o[i]=-1;
		    else
			o[i]=(v[i]*j*i)%15;// j 表示輸入阿法的次方數 得到每項的數 
		}
		     
		
		a[15]=0;  
		b[15]=0;  
		c[15]=0;  
		d[15]=0;  
		
		for(i=1;i<15;i++)
		{
			if(o[i]==-1) continue;
			a[15]+=a[o[i]];   b[15]+=b[o[i]];   c[15]+=c[o[i]];   d[15]+=d[o[i]];
		}
		if(v[0]==1)
	    a[15]+=1;
	    a[15]%=2,b[15]%=2,c[15]%=2,d[15]%=2;
		s[j]=check(a,b,c,d);
		
	}
		
	
	
	int sigma[3];
	if(plus(multi(s[1],s[2],0),s[3])!=-1)
	{
	            sigma[0]=s[1];
	            sigma[1]=divi(plus(multi(s[1],s[1],s[3]),s[5]),plus(multi(s[1],s[1],s[1]),s[3]));
	            sigma[2]=plus(plus(multi(s[1],s[1],s[1]),s[3]),multi(s[1],sigma[1],0));
	           
	            j=1,s[1]=-1,s[2]=-1,s[3]=-1;
	            for(i=0;i<15;i++)
	            {
		
		            
		            x=0;
		            if(sigma[0]==-1) y=-1;
		            else y=multi(sigma[0],i,0);
		            
		            if(sigma[1]==-1) z=-1;
					else z=multi(sigma[1],2*i,0);
					
					if(sigma[2]==-1) w=-1;
		            else w=multi(sigma[2],3*i,0);
						
		            if(plus(x,plus(y,plus(z,w)))==-1)
		            {
			            while(j<4)
		                {
			                s[j++]=i;
			                break;
		                }
             
		            }

	            }
	           
                
				s[1]=divi(0,s[1]);
                s[2]=divi(0,s[2]);
                s[3]=divi(0,s[3]);
                
               
                if(s[1]>=0)
                v[s[1]]=(v[s[1]]+1)%2;
                if(s[2]>=0)
                v[s[2]]=(v[s[2]]+1)%2;
                if(s[3]>=0)
                v[s[3]]=(v[s[3]]+1)%2;
                printf("解碼後的多項式V(X)=");
                for(i=0;i<15;i++)
                if(v[i]==1)
                {
                	if(i==0)
                	printf("%d",1);
                	else
                	printf("+X^%d",i);
				}
				if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0&&v[5]==0&&v[6]==0&&v[7]==0&&v[8]==0&&v[9]==0&&v[10]==0&&v[11]==0&&v[12]==0&&v[13]==0&&v[14]==0)
				{
					printf("0");
				}           
    }
	else
	{
	     sigma[0]=s[1];
	     for(i=0;i<15;i++)
	     {
	     	x=0;
	        y=(sigma[0]+i)%15;
	        if(plus(x,y)==-1)
            {
            	s[0]=i;
				break;
			}
			                 		
		 }
	     s[0]=divi(0,s[0]);
		 v[s[0]]=(v[s[0]]+1)%2;
		 printf("解碼後的多項式V(X)=");
         for(i=0;i<15;i++)
                if(v[i]==1)
                {
                	if(i==0)
                	printf("%d",1);
                	else
                	printf("+X^%d",i);
				}
				if(v[0]==0&&v[1]==0&&v[2]==0&&v[3]==0&&v[4]==0&&v[5]==0&&v[6]==0&&v[7]==0&&v[8]==0&&v[9]==0&&v[10]==0&&v[11]==0&&v[12]==0&&v[13]==0&&v[14]==0)
				{
					printf("0");
				}		
	}
	return 0;
}