main(v,V,m,M,c,C,i){char*p;for(v=0,V=0;scanf("%d-%d %c: %ms\n",&m,&M,&c,&p)>0;C=0){for(i=0;i<strlen(p);i++)C+=p[i]==c;v+=C>=m&C<=M;V+=p[m-1]==c^p[M-1]==c;}printf("%d %d\n",v,V);}

