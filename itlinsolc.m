function x = itlinsolc(ciA,vicA, b)
%   ITLINSOLC Summary of this function goes here
%   Detailed explanation goes here

% constants
I = 500;
E = 1e-9;

% sizes
n = size(ciA, 1);
d = size(ciA, 2);

% x
x = ones(n, 1);
xN = ones(n, 1);

% iteration matrices
[BJ, CJ] = itmatrix(ciA, vicA, b, n);


% Jacobi iterational method
for k = 1:I
    for i = 1:n
        xN(i) = BJ(i, :) * x(ciA(i, :)) + CJ(i);
    end
%     for i = 1:n
%         if( abs(b(i) - vicA(i, :) * x(ciA(i, :))) < E )
%             k
%             break
%         end
%     end
    if( abs(xN - x) < E )
        k
        break
    end
    x = xN;
end
