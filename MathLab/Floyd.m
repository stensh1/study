clc; clear;

coord_matrix = [[0,0]; [3,1]; [10,0];];

result = FloydWarshall(coord2adj(coord_matrix));

function [result] = FloydWarshall(graph)   
    num_of_nodes = size(graph, 1); %computing the size of graph, better to make an own var at the start (str. 3)
    result = graph; %var to operate

    %running through nodes from 1st to last
    for k=1:num_of_nodes
        for i=1:num_of_nodes
            for j=1:num_of_nodes
                if (result(i,j) > result(i,k) +  result(k,j))
                   result(i,j) = result(i,k) + result(k,j);
                end
            end
        end
    end   
end

function [adj_matrix] = coord2adj(coord_matrix)
    adj_matrix = [];
    for i = 1:size(coord_matrix, 1)
        for j = 1:size(coord_matrix, 1)
            if (i == j)
                adj_matrix(i, j) = 0;
            else
                adj_matrix(i, j) = 2 * (coord_matrix(j, 1) - coord_matrix(i,1)) / (coord_matrix(j, 2) - coord_matrix(i, 2));
                if (adj_matrix(i, j) == Inf) || (adj_matrix(i, j) == -Inf)
                    adj_matrix(i, j) = 0;
                end
            end
        end
    end
end
