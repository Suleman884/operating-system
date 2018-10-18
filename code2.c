#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int main(){
	int a[1000],sum=0,a1[10];
	int s1,s2,s3,s4,s5,s6,s7,s8,s9;
	int v1=0,v2=0,v3=0,v4=0,v5=0,v6=0,v7=0,v8=0,v9=0,v10=0;
	for(int i=0;i<1000;i++){
		a[i]=i;
	}
	int cpid1=fork();
	if(cpid1==0){
		for(int i1=0;i1<100;i1++){
			v1+=a[i1];
		}
		sum+=v1;
		exit(sum);
	}
	else{
		s1=-1;
		wait(&s1);
		int cpid2=fork();
		if(cpid2==0){
			for(int i2=100;i2<200;i2++){
				v2+=a[i2];
			}
			sum+=v2;
			exit(sum);
		}
		else{
			s2=-1;
			wait(&s2);
			int cpid3=fork();
			if(cpid3==0){
				for(int i3=200;i3<300;i3++){
					v3+=a[i3];
				}
				sum+=v3;
				exit(sum);
			}
			else{
				s3=-1;
				wait(&s3);
				int cpid4=fork();
				if(cpid4==0){
					for(int i4=300;i4<400;i4++){
						v4+=a[i4];
					}
					sum+=v4;
					exit(sum);
				}
				else{
					s4=-1;
					wait(&s4);
					int cpid5=fork();
					if(cpid5==0){
						for(int i5=400;i5<500;i5++){
							v5+=a[i5];
						}
						sum+=v5;
						exit(sum);
					}
					else{
						s5=-1;
						wait(&s5);
						int cpid6=fork();
						if(cpid6==0){
							for(int i6=500;i6<600;i6++){
								v6+=a[i6];
							}
							sum+=v6;
							exit(sum);
						}
						else{
							s6=-1;
							wait(&s6);
							int cpid7=fork();
							if(cpid7==0){
								for(int i7=600;i7<700;i7++){
									v7+=a[i7];
								}
								sum+=v7;
								exit(sum);
							}
							else{
								s7=-1;
								wait(&s7);
								int cpid8=fork();
								if(cpid8==0){
									for(int i8=700;i8<800;i8++){
										v8+=a[i8];
									}
									sum+=v8;
									exit(sum);
								}
								else{
									s8=-1;
									wait(&s8);
									int cpid9=fork();
									if(cpid9==0){
										for(int i9=800;i9<900;i9++){
											v9+=a[i9];
										}
										sum+=v9;
										exit(sum);
									}
									else{
										s9=-1;
										wait(&s9);
										for(int i10=900;i10<1000;i10++){
											v10+=a[i10];
										}
										sum+=v10;
									}
								}
							}
						}
					}
				}
			}		
		}
	}
	printf("Sum = %d",sum);
	return 0;
}
