function [BJ, CJ] = itmatrix(ciA, vicA, b, n)

a = zeros(n, 1);
for i = 1:n
    a(i) = vicA(i, ciA(i, :) == i);
end

BJ = -vicA ./ a;

for i = 1:n
    BJ(i, ciA(i, :) == i) = 0;
end

CJ = b ./ a;