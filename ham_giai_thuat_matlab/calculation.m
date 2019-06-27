clc;

fileID = fopen('hinhtron.txt','w');

for i=0:1:100
    xp=20+150*cos(pi*i/50);
    yp=20+150*sin(pi*i/50);
    zp=550;
    p1=0;
    p2=0;
    p3=0;
q(1)=xp;
q(2)=yp;
q(3)=zp;
q(4)=p1;
q(5)=p2;
q(6)=p3;
q(7:9)=vpa(function_solve(0,0,xp,yp,zp,p1,p2,p3));
q(10:12)=vpa(function_solve(-pi/6,-pi/2,xp,yp,zp,p1,p2,p3));
q(13:15)=vpa(function_solve(-2*pi/3,-2*pi/3,xp,yp,zp,p1,p2,p3));
q(16:18)=vpa(function_solve(-5*pi/6,5*pi/6,xp,yp,zp,p1,p2,p3));
q(19:21)=vpa(function_solve(2*pi/3,2*pi/3,xp,yp,zp,p1,p2,p3));
q(22:24)=vpa(function_solve(pi/2,pi/6,xp,yp,zp,p1,p2,p3));
fprintf(fileID,'%0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f %0.4f',q);
fprintf(fileID,'\n');
disp(q)
end
fclose(fileID);