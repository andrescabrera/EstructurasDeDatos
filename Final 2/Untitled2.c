void intercalar(int x[], int y[], int n){
 int i, j=1, z[], k=0;

 for(i=0;i<n;i+2){

        z[i]=x[k];
        z[j]=y[k];
        k++;
        j+2;


 }
mostrar(z, n);
}
