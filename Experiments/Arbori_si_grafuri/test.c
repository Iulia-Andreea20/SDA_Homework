   // while(node < 10)
    // {
    //     minimum = 10;
    //     visited_nodes[k] = node;
    //     k++;
    //     for(i = 0; i < 11; i++)
    //     {
    //         if(graph[i].node1 == node)
    //         {
    //             edges[position].node1 = graph[i].node1;
    //             edges[position].node2 = graph[i].node2;
    //             edges[position].cost = edges[i].cost;
    //             position++; 
    //         }
    //         else if(graph[i].node1 > node)
    //         {
    //             break;
    //         }
    //     }
        
    //         for(x = 0; x < position; x++)
    //         {
    //             ok_cycle = 0;
    //             for(y = 0; y < 11; y++)
    //             {
    //                 if(edges[x].node1 == graph[y].node1)
    //                 {
    //                     for(j = y + 1; j < 11; j++)
    //                     {
    //                         if(edges[x].node2 == graph[j].node1)
    //                         {
    //                             ok_cycle = 1;
    //                             break;
    //                         }
    //                     }
    //                 }
    //                 if(ok_cycle == 1)
    //                 {
    //                     break;
    //                 }
    //             }
    //             if(ok_cycle == 1)
    //             {
    //                 for(y = x; y <= position; y++)
    //                 {
    //                     edges[y].node1 = edges[y + 1].node1;
    //                     edges[y].node2 = edges[y + 1].node2;
    //                     edges[y].cost = edges[y + 1].cost;
    //                 }
    //                 position--;
    //             }
                
    //         }
        
    //     for(j = 0; j < position; j++)
    //     {
    //         if(edges[j].cost < minimum)
    //         {
    //             minimum = edges[j].cost;
    //         }
    //     }
    // }