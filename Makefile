# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2017/11/21 06:34:22 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
FLAGS	=	-Wall -Werror -Wextra
SRC		=	$(wildcard *.c)
OBJ		=	$(SRC:.c=.o)
LIBFT	=	libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(NAME).h
	@gcc $(OBJ) -o $(NAME) $(FLAGS) 

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

exec:
	@./$(NAME)  34   33   12   96   30   61    8   60   29   79   43   37   52   47   18   50   15   24   78   88   62   23   22    4   41   73    6   35   28   53   46   66   65   14   39   17   82   93   97   51   20   31   25   38   80   76   57   55    3   77   32   59   84   19    5   86   58   95   42   63   75  100   21   48   68   54   44   85   71   45    7   99   92   70   74   56   16   87   91   89    9   69   26   10   40   83    1   90   27   11   13   64   67   98   94    2    0   81   49   72   36
 
f: all exec

ff: re exec
