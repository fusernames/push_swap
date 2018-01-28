# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcaroff <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 15:15:20 by alcaroff          #+#    #+#              #
#    Updated: 2018/01/28 16:39:11 by alcaroff         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS			=	-Wall -Werror -Wextra
LIBFT			=	libft/libft.a
LIBFT_INCLUDES	=	libft/$(INCLUDES)
INCLUDES		=   includes
SRC				=	\
	check_exceptions.c \
	lst_manager.c \
	op.c \
	exec.c \
	parser.c \
	ps_atoi.c
SRC_PS			=	\
	push_swap.c \
	ps_findindex.c \
	ps_findpath.c \
	ps_findvalue.c \
	ps_goto.c \
	resolve.c \
	resolve_findbestway.c \
	resolve_short.c
SRC_CK			=	\
	checker.c
OBJ				=	$(SRC:.c=.o)
OBJ_PS			=	$(SRC_PS:.c=.o)
OBJ_CK			=	$(SRC_CK:.c=.o)

all: $(LIBFT) push_swap checker

push_swap: $(OBJ) $(OBJ_PS)
	gcc $(OBJ) $(OBJ_PS) -o push_swap $(FLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LIBFT)

checker: $(OBJ) $(OBJ_CK)
	gcc $(OBJ) $(OBJ_CK) -o checker $(FLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C libft

%.o: %.c
	@gcc -c $< -o $@ $(FLAGS) -I $(INCLUDES) -I $(LIBFT_INCLUDES)

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(OBJ) $(OBJ_PS) $(OBJ_CK)

fclean: clean
	@$(MAKE) fclean -C libft
	@rm -rf push_swap checker

re: fclean all

exec:
	@./push_swap  75   71    9   68   76   47   61   83    2   14   44   39   30   38    8   99    7   31   43    5   70   22   93   67   27   17   28   77   59   29   87   90   33   16   37   72   80   79   19    0   42   52   55    4   46   57   25   45   41   49   18   53   48   74   97   24   91   40   34   64   95   60   86   56   84   32   81   85    1   88  100   50   26    3    6   62   66   69   94   12   98   35   36   63   11   78   23   13   82   73   65   92   58   54   89   21   10   96   51   15   20  

f: all exec

ff: re exec
