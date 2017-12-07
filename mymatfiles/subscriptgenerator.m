clear;
N = 10000;
x = zeros(1,N);
for i = 1: N
    x(i)=i;
end
var.time = 1:N;
var.signals.values = x;
var.signals.dimensions = 1;
var.signals.label = 'subscripts';
save subscripts.mat var;