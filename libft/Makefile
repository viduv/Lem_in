FLAGS= -Wall -Wextra -Werror

SRC= ft_memset.c\
	 ft_bzero.c\
	 ft_memcpy.c\
	 ft_memccpy.c\
	 ft_memmove.c\
	 ft_memchr.c\
	 ft_memcmp.c\
	 ft_strlen.c\
	 ft_strdup.c\
	 ft_strcpy.c\
	 ft_strncpy.c\
	 ft_strcat.c\
	 ft_strncat.c\
	 ft_strlcat.c\
	 ft_strchr.c\
	 ft_strrchr.c\
	 ft_strstr.c\
	 ft_strnstr.c\
	 ft_strcmp.c\
	 ft_strncmp.c\
	 ft_atoi.c\
	 ft_memalloc.c\
	 ft_memdel.c\
	 ft_strnew.c\
	 ft_strdel.c\
	 ft_strclr.c\
	 ft_putchar.c\
	 ft_putstr.c\
	 ft_putendl.c\
	 ft_putnbr.c\
	 ft_striter.c\
	 ft_striteri.c\
	 ft_strmap.c\
	 ft_strmapi.c\
	 ft_strequ.c\
	 ft_strnequ.c\
	 ft_strsub.c\
	 ft_strjoin.c\
	 ft_strtrim.c\
	 ft_strsplit.c\
	 ft_itoa.c\
	 ft_putchar_fd.c\
	 ft_putstr_fd.c\
	 ft_putendl_fd.c\
	 ft_putnbr_fd.c\
	 ft_lstnew.c\
	 ft_lstdelone.c\
	 ft_strsplitpatab.c\
	 ft_lstdel.c\
	 ft_lstadd.c\
	 ft_lstiter.c\
	 ft_lstmap.c\
	 ft_strjoinfree.c\
	 ft_strjoinfree1.c\
	 ft_strjoinfree2.c\
	 ft_strjoin3.c\
	 get_next_line.c\
	 ft_check_str.c \

LIB = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
OBJ = $(SRC:.c=.o)
RM = rm -rf
RANLIB = ranlib
CG = \033[92m
CY =  \033[93m
CE = \033[0m
CB = \033[34m

all: $(LIB)

$(LIB):  $(OBJ)
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Creating Library$(CE)";
	@$(AR) $(LIB) $(OBJ)
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Indexing Library$(CE)";
	@$(RANLIB) $(LIB)

nohd: $(OBJ)
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Creating Library$(CE)";
	@$(AR) $(LIB) $(OBJ)
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Indexing Library$(CE)";
	@$(RANLIB) $(LIB)

nohdclean:
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Cleaning object files...$(CE)";
	@$(RM) $(OBJ)

nohdfclean: nohdclean
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Cleaning Library...$(CE)";
	@$(RM) $(LIB)

%.o: %.c
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Compiling $<$(CE)";
	@$(CC) $(CFLAGS) -c $< -o $@

clean: 
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Cleaning object files...$(CE)";
	@$(RM) $(OBJ)

fclean: clean
	@echo "$(CY)[LIBFT] :$(CE) $(CG)Cleaning Library...$(CE)";
	@$(RM) $(LIB)

re: fclean all

.PHONY: all clean fclean re
