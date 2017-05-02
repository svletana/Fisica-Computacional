z=60; n=128;

function [S,perco]=proc(b)
  B=strsplit(cell2mat(b),"--");
  S=str2num(cell2mat(B(1,1)));
  perco=str2num(cell2mat(B(1,2)));
end

function m2 = iter(n,z)
  m2 = zeros(1,z);

  [a,b]=system("./out 128 60 1");
  e = strsplit(b,"FIN");
 %e(1,i)
  for i=1:z
    [ss,pperco]=proc(e(1,i));
    
    %for j=1:(n*n)
      q=find(pperco==1);
      ss(q-1)=0;
      
      ns=zeros(1,length(ss));
      sx = zeros(1,length(ss));
      for k=(1:length(ss))
        h=ss(k);
        if ss(k)~=0 
          ns(ss(k))=sum(ss==h);
          sx(ss(k))=ss(k);
        end
      end
      
      m2(i)=sum(sx.*sx.*ns);
      %end
    end
end

x=100;
resultados = zeros(x,z);
for i=1:x
  resultados(i,:) = iter(n,z);
end
resultados

mdos=zeros(1,z)
for j=1:z
  mdos(j)=sum(resultados(:,j))/x
end
