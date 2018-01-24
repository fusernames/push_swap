# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2018/01/24 20:10:22 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
FLAGS		=	-Wall -Werror -Wextra
LIBFT		=	libft/libft.a
LIBFT_INCLUDES =	libft/$(INCLUDES)
INCLUDES	=   includes
SRC			=	$(wildcard *.c)
OBJ			=	$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@gcc $(OBJ) -o $(NAME) $(FLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LIBFT)

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(OBJ)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -rf $(NAME)

re: fclean all

exec:
	@./$(NAME)  75   71    9   68   76   47   61   83    2   14   44   39   30   38    8   99    7   31   43    5   70   22   93   67   27   17   28   77   59   29   87   90   33   16   37   72   80   79   19    0   42   52   55    4   46   57   25   45   41   49   18   53   48   74   97   24   91   40   34   64   95   60   86   56   84   32   81   85    1   88  100   50   26    3    6   62   66   69   94   12   98   35   36   63   11   78   23   13   82   73   65   92   58   54   89   21   10   96   51   15   20  

f: all exec

ff: re exec
