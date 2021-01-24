#define SIZE 4

void moveUp(int arr[][SIZE], int * score){                                        //Spiellogik moveUP
    short moved = 0;                                                 //Var to check if we need to spawn a new number.
    for(int i=0; i<SIZE; i++ ){                                      //column 
        
        for(int j=1; j<SIZE; j++){                                   //row
            if(arr[j][i]){                                           //Check if value y,x is Zero. Execute if not.
                for(int k=(j-1); k>=0; k--){                         //Checks values ABOVE current y,x                   
                    if(!arr[k][i]){                                //Checks for zero in field above
                        arr[k][i] = arr[k+1][i];                     //arr[k][i]= checking field  arr[k+1][i]= field one below.
                        arr[k+1][i] = 0;
                        moved = 1;                                   //got here: made a move
                    } else break;                                    //Leave loop when there are no more zeros.
                }                
            }
        }

        for(int j=1; j<SIZE; j++ ){                                 //Start counting at row 1
            if(arr[j][i] && (arr[j][i] == arr[j-1][i])){            //if two values are identical and not zero.
                arr[j-1][i] =  arr[j][i] * 2;                       //Set upper to 2* lower
                arr[j][i] = 0;                                      //set old value 0
                *score += arr[j-1][i];
                moved = 1;                                          //Got here, made a move.
            }
        }

        for(int j=1; j<SIZE; j++){
            if(arr[j][i]){
                for(int k=(j-1); k>=0; k--){
                    if(!arr[k][i]){
                        arr[k][i] = arr[k+1][i];
                        arr[k+1][i] = 0;
                    } else break;
                }
            }
        }
    }
    if(moved) spawnNumber(arr); 
}


void moveDown(int arr[][SIZE], int * score){
    short moved = 0; 
    for(int i=0; i<SIZE; i++ ){                                      
        
        for(int j=SIZE-2; j>=0; j--){         
            if(arr[j][i]){                                           
                for(int k=(j+1); k<SIZE; k++){                        
                    if(!arr[k][i]){                                
                        arr[k][i] = arr[k-1][i];                     
                        arr[k-1][i] = 0;
                        moved = 1;
                    } else break;                                    
                }                
            }
        }

        for(int j=SIZE-2; j>=0; j-- ){                               
            if(arr[j][i] && (arr[j][i] == arr[j+1][i])){                           
                arr[j+1][i] = arr[j][i] * 2;                       
                arr[j][i] = 0;
                moved = 1;
                *score += arr[j+1][i];
            } 
        }

        for(int j=SIZE-2; j>=0; j--){                                 
            if(arr[j][i]){                                           
                for(int k=(j+1); k<SIZE; k++){                                       
                    if(!arr[k][i]){                                
                        arr[k][i] = arr[k-1][i];                     
                        arr[k-1][i] = 0;
                    } else break;                                   
                }                
            }
        }
        
    }
    if(moved) spawnNumber(arr); 
}

void moveLeft(int arr[][SIZE], int * score){                                      
    short moved = 0;        
    for(int j=0; j<SIZE; j++){                                         
        for(int i=1; i<SIZE; i++ ){                                  
            if(arr[j][i]){                                           
                for(int k=(i-1); k>=0; k--){                         
                    if(!arr[j][k]){                                
                        arr[j][k] = arr[j][k+1];                     
                        arr[j][k+1] = 0;
                        moved = 1;
                    } else break;                                    
                }                
            }
        }

        for(int i=1; i<SIZE; i++ ){                                 
            if(arr[j][i] && (arr[j][i] == arr[j][i-1])){                           
                arr[j][i-1] =  arr[j][i] * 2;                       
                arr[j][i] = 0;
                moved = 1;
                *score += arr[j][i-1];
            } 
        }

        for(int i=1; i<SIZE; i++ ){                               
            if(arr[j][i]){                                           
                for(int k=(i-1); k>=0; k--){                         
                    if(!arr[j][k]){                                
                        arr[j][k] = arr[j][k+1];                     
                        arr[j][k+1] = 0;
                    } else break;                                    
                }                
            }
        }
    }
    if(moved) spawnNumber(arr);
}

void moveRight(int arr[][SIZE], int * score){
    short moved = 0; 
    for(int i=0; i<SIZE; i++ ){                                      
        
        for(int j=SIZE-2; j>=0; j--){         
            if(arr[i][j]){                                           
                for(int k=(j+1); k<SIZE; k++){                        
                    if(!arr[i][k]){                                
                        arr[i][k] = arr[i][k-1];                     
                        arr[i][k-1] = 0;
                        moved = 1;
                    } else break;                                    
                }                
            }
        }

        for(int j=SIZE-2; j>=0; j-- ){                               
            if(arr[i][j] == arr[i][j+1]){                           
                arr[i][j+1] = arr[i][j] * 2;                       
                arr[i][j] = 0;
                moved = 1;
                *score += arr[i][j+1];
            } 
        }

        for(int j=SIZE-2; j>=0; j--){         
            if(arr[i][j]){                                           
                for(int k=(j+1); k<SIZE; k++){                        
                    if(!arr[i][k]){                                
                        arr[i][k] = arr[i][k-1];                     
                        arr[i][k-1] = 0;
                    } else break;                                    
                }                
            }
        }
    }
    if(moved) spawnNumber(arr); 
}

