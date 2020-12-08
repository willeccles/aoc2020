main(m,i,n){char*p;for(m=0;scanf("%ms",&p)>0;m=i>m?i:m)for(i=0,n=0;n<10;n++)i|=(p[n]==66|p[n]==82)<<9-n;printf("%d\n",m);}
