main(c,t){char*l;for(c=0,t=0;scanf("%ms",&l)>0;c+=3)t+=l[c%31]==35;printf("%d\n",t);}
