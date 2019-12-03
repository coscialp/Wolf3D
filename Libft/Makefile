# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: coscialp <coscialp@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/10/25 18:12:55 by coscialp     #+#   ##    ##    #+#        #
#    Updated: 2019/12/03 19:27:18 by coscialp    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY:			all clean fclean re bonus

NAME	=		libft.a

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[1;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									PATH                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

SRC_PATH = src/
OBJ_PATH = obj/
INC_PATH = includes/

SSRC_PATH = $(addprefix $(SRC_PATH), str/)
SOBJ_PATH = $(addprefix $(OBJ_PATH), str/)

CSRC_PATH = $(addprefix $(SRC_PATH), char/)
COBJ_PATH = $(addprefix $(OBJ_PATH), char/)

ISRC_PATH = $(addprefix $(SRC_PATH), math/)
IOBJ_PATH = $(addprefix $(OBJ_PATH), math/)

MSRC_PATH = $(addprefix $(SRC_PATH), mem/)
MOBJ_PATH = $(addprefix $(OBJ_PATH), mem/)

LSRC_PATH = $(addprefix $(SRC_PATH), lst/)
LOBJ_PATH = $(addprefix $(OBJ_PATH), lst/)

PSRC_PATH = $(addprefix $(SRC_PATH), ft_printf/)
POBJ_PATH = $(addprefix $(OBJ_PATH), ft_printf/)

SFSRC_PATH = $(addprefix $(SRC_PATH), ft_scanf/)
SFOBJ_PATH = $(addprefix $(OBJ_PATH), ft_scanf/)

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									SRCS                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

SINC_NAME = libft.h
SSRC_NAME = ft_putchar.c ft_putchar_fd.c\
			ft_putendl.c ft_putendl_fd.c ft_strncmp.c\
			ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strcmp.c\
			ft_strcpy.c ft_strdel.c ft_strdup.c ft_strjoin.c\
			ft_strfjoin.c ft_strlen.c ft_strstr.c ft_substr.c\
			ft_split.c get_next_line.c\
			ft_strncpy.c ft_strchr.c ft_strndup.c\
			ft_strlcat.c ft_strlcpy.c ft_strmapi.c ft_strtrim.c\
			ft_strnlen.c ft_strrchr.c ft_strnstr.c ft_free_tab.c ft_put_tab.c\
			ft_split_line.c ft_strwcdup.c ft_strisdigit.c

CINC_NAME = libft.h
CSRC_NAME = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isspace.c ft_isprint.c\
			ft_islower.c ft_isupper.c ft_isdigit.c

IINC_NAME = libft.h
ISRC_NAME = ft_atoi.c ft_putnbr_fd.c ft_putnbr_base.c ft_itoa.c ft_itoa_base.c ft_itoa_ll_base.c ft_itoa_u_base.c

MINC_NAME = libft.h
MSRC_NAME = ft_memset.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
			ft_memmove.c ft_calloc.c ft_bzero.c ft_memdel.c

LINC_NAME = libft.h
LSRC_NAME = ft_lstadd_back.c ft_lstadd_front.c ft_lstnew.c ft_lstiter.c\
			ft_lstlast.c ft_lstnew.c ft_lstsize.c

PINC_NAME = libftprintf.h
PSRC_NAME = ft_printf.c handler_convert.c handler_convert_int.c\
			ft_is.c ft_analyser.c ft_set_flags.c ft_set_width.c ft_apply_flags.c\
			ft_apply_convert.c ft_strjoin_zero.c ft_itoa_pf.c ft_dprintf.c

SFINC_NAME = ft_scanf.h
SFSRC_NAME = ft_scanf.c handler_convert_sf.c read_stdin.c

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									VAR                                       ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

SOBJ_NAME = $(SSRC_NAME:.c=.o)
SOBJ = $(addprefix $(SOBJ_PATH), $(SOBJ_NAME))
SINC = $(addprefix $(INC_PATH), $(SINC_NAME))

COBJ_NAME = $(CSRC_NAME:.c=.o)
COBJ = $(addprefix $(COBJ_PATH), $(COBJ_NAME))
CINC = $(addprefix $(INC_PATH), $(CINC_NAME))

IOBJ_NAME = $(ISRC_NAME:.c=.o)
IOBJ = $(addprefix $(IOBJ_PATH), $(IOBJ_NAME))
IINC = $(addprefix $(INC_PATH), $(IINC_NAME))

MOBJ_NAME = $(MSRC_NAME:.c=.o)
MOBJ = $(addprefix $(MOBJ_PATH), $(MOBJ_NAME))
MINC = $(addprefix $(INC_PATH), $(MINC_NAME))

LOBJ_NAME = $(LSRC_NAME:.c=.o)
LOBJ = $(addprefix $(LOBJ_PATH), $(LOBJ_NAME))
LINC = $(addprefix $(INC_PATH), $(LINC_NAME))

POBJ_NAME = $(PSRC_NAME:.c=.o)
POBJ = $(addprefix $(POBJ_PATH), $(POBJ_NAME))
PINC = $(addprefix $(INC_PATH), $(PINC_NAME))

SFOBJ_NAME = $(SFSRC_NAME:.c=.o)
SFOBJ = $(addprefix $(SFOBJ_PATH), $(SFOBJ_NAME))
SFINC = $(addprefix $(INC_PATH), $(SFINC_NAME))

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									FLAG                                      ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

FLAGS = -Wall -Werror -Wextra -O3 -g3 #-fsanitize=address#-fsanitize=undefined 

# ┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓
# ┃									RULES                                     ┃
# ┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛

all : $(NAME)

$(NAME): $(SOBJ) $(IOBJ) $(LOBJ) $(MOBJ) $(POBJ) $(COBJ) $(SFOBJ)
	@ar rcs $(NAME) $(SOBJ) $(IOBJ) $(LOBJ) $(MOBJ) $(POBJ) $(COBJ) $(SFOBJ)
	@echo "	\033[2K\r$(DARK_BLUE)Libft:	$(LIGHT_GREEN)Updated\033[0m"

$(SOBJ_PATH)%.o: $(SSRC_PATH)%.c $(SINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(COBJ_PATH)%.o: $(CSRC_PATH)%.c $(CINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(IOBJ_PATH)%.o: $(ISRC_PATH)%.c $(IINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(MOBJ_PATH)%.o: $(MSRC_PATH)%.c $(MINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(LOBJ_PATH)%.o: $(LSRC_PATH)%.c $(LINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(POBJ_PATH)%.o: $(PSRC_PATH)%.c $(PINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

$(SFOBJ_PATH)%.o: $(SFSRC_PATH)%.c $(SFINC)
	@if test ! -d $(dir $@); then mkdir -p $(dir $@); fi
	@gcc $(FLAGS) -I $(INC_PATH) -o $@ -c $<
	@printf "\033[2K\r$(PINK)Compiling...	\033[37m$<\033[36m \033[0m"

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

dracaufeu :		$(SOBJ) $(IOBJ) $(LOBJ) $(MOBJ) $(POBJ)
	@ar rcs $(NAME) $(SOBJ) $(IOBJ) $(LOBJ) $(MOBJ) $(POBJ)
	@echo "$'[31m                                         @MnM                                                                                                         "
	@echo "                                        @n++x                                                 W@W@                                                    "
	@echo "                                       @n*;n@                                                 Mn+x@                                                   "
	@echo "                                      @x*;*W                                      WnzW         W*inW@                                                 "
	@echo "                                     @n*;;nW                                    @M ixW         Wx;; W                                                 "
	@echo "                                    @x*;;iW                                   @Mn*ix@           W+:;x@                                                "
	@echo "                                    M ;;; @                                  Mz*;izW            Wn;;in@                                               "
	@echo "                                   Wz;;;;z@                                @M ;;;zM              x+;;*n@                                              "
	@echo "                                   W+;;;*x                                nxi;;;zx               Wn;;;zM                                              "
	@echo "                                  Wx;;;; W                              Wn+;;;;n@                @Mi;;in@                                             "
	@echo "                                  Wz;;;;nW                            @@xi;;;; M                  M+;;;+n                                             "
	@echo "                                  n*;;;;x@                           Wx ;;;;; x                   Mz;;;;n@                                            "
	@echo "                                 @n;;;;ix                           @x+;;;;; M                     xi;;;+M                                            "
	@echo "                                 W ;;;;+@                          @n*ii;;;+n@                     M+;;;;M                                            "
	@echo "                                 x+;;;i+@                        @Wziiiiii+n@                      W ;;;;zW                                           "
	@echo "                                 xi;;;i+W                   M@  @x+iiiiii*M@                       @ni;;;*x                                           "
	@echo "                                 xi;;;i @                 @MzW  M+iiiiii*zM@@                      @zi;;iix@                                          "
	@echo "                                Wzii;ii                  @n nW@z*iiiiii*zz+nx                       M*iiiizW                                          "
	@echo "                                x iiiii                 @Mz M@Miiiiii+ +;;zx@                       n*iiii*W                                          "
	@echo "                                W+iiiiiz                Wz+zMniiii*+ *;;;z@                         @+iiiiin@                                         "
	@echo "                                @*iiiiiz              WMxz +*iii*+ *iiiizW                          @+iiiii*MW                                        "
	@echo "                                Miiiiiiz@           @xz+;;i*iiiiiiiiii*nM                           @ iiiiii+nW                                       "
	@echo "                               @niiiiiizx          WM*i;;;iii**iiiiii*xM                            @ iiii*ii+zM                                      "
	@echo "                               n iiiiii zM        Wxi*i;;ii+zziiiiii+MW                             @ iiii+*ii*nW@                                    "
	@echo "                              Wziiiiiii zn       @x*;+;;i n;,*iiiiii+*nM                            @ iiii**iii*zx@                                   "
	@echo "                             Mzii*iiiii +x@     @x ;*i;*zz ':iiiii*iii*n@                           @ iiii*+iiiii+xM                                  "
	@echo "                            n iii*iiiii +nM  x  zz*i*i xn  :;;iii+;**ii*xW                          W+iiiii iiiiii*zxW                                "
	@echo "                          @x iiii+iiiiiz zW W ;;**;ii*iiii;;;iii :.,+iii M                         Mx+;iiii iiiiiiii+xW@                              "
	@echo "                         Wx+iiiii+iiiiiz  W Wi;*i;iiiiiiiiiii*+z+i;,;*iiizW                        xn+;;iii+*iiiiiiii*nx@                             "
	@echo "                        @x*iiiiii+iiiiiz+ M@x;iii iiii****+++ z+iiii:+iiiinW                 @M   @M +;;iiii iiiiiiiiii+x@                            "
	@echo "                       Wn*iiiiiii+iiii*z+ M@niii+***+     zz *iiiiiii**iii*x@                MxW  Mn+ ;;;iii iiiiiiiiiii+xW                           "
	@echo "                       M*iiiiiiii+iiii+n+ nMz***++ z*z+  +*iiiiiiiiiii iiii+M                Wzn@ M +n;;;;ii*+iiiiiiiiiii*xM                          "
	@echo "                     @xi;;iiiiiii+iiii n  nWnz+ +zz*;+iiiiiiiiiiiiiii*n*iiiizW               @nzMxz+zn ;;;iii+*iiiiiiiiiii*M@                         "
	@echo "                    Wzi;;;;iiiiii iiiizzz  nMx +  i+i*iiiiiiiiiiiiii* * iiii*x@              @niMx  nzn+;;iiii+iiiiiiiiiiii*xW                        "
	@echo "                   xzi;;;;;iiiii*+iiiinzn  nWWxzzii* iiiiiiiiiiiiii++ii;+iiii x               W*z +znzzn+;iiiii+iiiiiiiiiiii*nM                       "
	@echo "                  @z;;;;;;;iiiii+*iiiinzn   M  @M*iiiiiiiiiiiiiiii *iii,:+iiiix@              @+iz+xzzzzn ;iiiiiiiiiiiiiiiiiiinW                      "
	@echo "                @Wz;;;;;;;;iiiii iiii*nzzz+ xW  @x ** znxWxn +ii+nziiii,.;+iii+M              xz; nzzzzzznn*iiiiiiiiiiiiiiiiii;zn                     "
	@echo "                M ;;;;;;;;;iiii*+iiii*nzzn+  W   @@zWWM     @W@@M@x+ii;...i*iiinW            Wxz;inzzzzzzzzx+iiii+iiiiiiiiiiiii; M                    "
	@echo "               W ;;;;;;;;;iiiii*iiiii nzznz++xM                   @zii:....*iii*x           @Mzn*;+zzzzzzzzzn *ii*+iiiiiiiiiiii;;zW                   "
	@echo "             @W ;;;;;;;;;;iiiiiiiiiiizzzzzn + x@                   W+;.....,+iiin@         Wxnnx ;;nzzzzzzzzzz iii *iiiiiiiiiiii;; M                  "
	@echo "             Mz;;;;;;;;;;iiiiiiiiiii+zzzzzzn+ nx                   Wz.......;*ii+x         MnnnM+i;+zzzzzzzzzzzziii iiiiiiiiiiii;;izW                 "
	@echo "            @n;;;;;;;;;;;iiiiiiiiii*nzzzzzzzz+ xM                   M,.......+ii;x@      WWxnzxn*+;inzzzzzzzzzznzii*+iiiiiiiiiiiii; W                 "
	@echo "            W+;;;;;;;;;;iiiii*iiii*zzzzzzzzzn   x                   M*.......:+ii M@WM@@Wnnznxxzi+iinnnzzzzzzzzzn ii+*iiiiiiiiiiiiiz                  "
	@echo "           Wx;;;;;;;;;;;iiii*+iiii zzzzzzzzzzn++n@@                 @n........**iixMxnnnnnnnMnx+i*iiznnnnzznnnnnnx ii *iiiiiiiiiiii M               @M"
	@echo "           W ;;;;;;;;;;;iiii iiii zzznzzzzzzzzz++ zx@@              Wn,.......,+iinxnnnnnnxMxx+iiiii+xnnnnnnnnnnnnx+ii iiiiiiiiiiii+W              W*i"
	@echo "          @xi;;;;;;;;;;;iii *iii+zzzz nzzzzzzznz++  nnM@      @xW@  Wxi........;+i+nnnnxxxxz+*iiii+iinnnnnnnnnnnnnnx+i*+iiiiiiiiii**n               * "
	@echo "          Mnii;;;;;;;;;;ii+*iii+nzzzzzinzzzzzzznnz  zznxxW@@xxxnnxn@@x*.........+i;+xnxxnnnniiiiii*+i nnnnnnnnnnnnnnx*i+*iiiiiiiii*in             z**n"
	@echo "          M+i;;;;;;;;;;;i++iii*nzzzzzn**nzzzzzzzzzxxnnnnnxMMnzzzznnxxz+.........:+ii* xxnnnx+iiiiii i*xnnnnnnnnnnnnnnnii *iiiiiiiiiix@           M*** "
	@echo "          M*i;;;;;;;;;;i*+iii*nzzzzzzzz;+nzzzzzzzznnxxxnnzzznznnnnzzM*+,.........*iiiii+xnnnniiiiii* izxnnnnnnnnnnnnnx ii iiiiiiiiiinW            ***W"
	@echo "         Wz*;;;;;;;;;;;i+iiiinzzzzzzzzni; zzzzzzzznnnnnxxxxxnnnnnznz*i*:.......,.,+iiiii*nnnx+iiiiii **xnMMxnnnnnnnxMnM*i* iiiiiiiii W          W****@"
	@echo "         x+i;;;;;;;;;;;+iiiizzzzzzzzzzzz;;zzzzzzznnnnnnnnnnnxxnznn*;iii;......:,..*iiiiii*xnnniiiiii*** Mx@nxnnnnnxMM Mnii++iiiiiiii+M          xi***n"
	@echo "        Mz+;;;;;;;;;;;+iiii nzzzzzzzzzzni;inzzzzznnnnnnnnnnnnnxxzi;;iiii,::.......:+iiiiii xMM*iiiiii*i*x  @nnMxnnxx  @M*ii iiiiiiii*M          x***iM"
	@echo "       Wx*i;;;;;;;;;;+iiii+nzzzzzzzzzzzz ;;+nnznnnnnnnnnnnnnnnnz;;;;;ii*...........*iiiiiiinMW iiiiiiiii+W    @Wxnx@   @zii*+iiiiiii+nW         x***+ "
	@echo "      @n*+;;;;;;;;;;*iiii+nzzzzzzzzzzzzzni;;znnnnnnxz nxnnnnnnx;;;;;iii*...........:+iiiiii*xMniiiiiii*i*x@    @nxMW   @z*ii+iiiiii*+ W         x***  "
	@echo "      Wz*+;;;;;;;;;**;ii*nzzznzzzzzzzzznn+;;i* xxxz*;;i xnnnnnz;;;;iiii*.........,,.+iiiiiii WM*iiiiii+++zW     @nM     x ii**iiiii ++x         x***n "
	@echo "     Wn*++;;;;;;;;i+;iiinzzzzxzzzzzzznnnnn;;;*;i+i;;;;;; xnnnx+;iiiiiii*......,..,,.i*iiiii*ixn iiiii* z+ @             Wxiii*iiiiiz+ z         n***x "
	@echo "     xzi++;;;;;;;;+iiii zzznxxzzzzzzxWWMMxi;;;;;;;;;;;;;;nnnnxiiiiiiiii*,,,,,....,..,+iiiiiii+nniii*++ z  M              M iiiiiii+z+ x        W****  "
	@echo "    @x** +;;;;;;;*iiii*nzznMxzzzzzzxM    W ;;;;;;;;;;;;;;znnnniiiiiiiii*.....,,......* ziiiiii Wz**++++z+z@              Wniiiiiii   zx       M*****  "
	@echo "    Wn*+ *;;;;;;i*iii*xnnznnxzzzzzxM      x ;;;i;;;;;;;;;+nnx iiiiiiiii*.....,,......; Mniiiiiinxn+++++z+nW               x+iiiiiin  zM      xi*****+@"
	@echo "    @+++z;;;;;;;+;iiizzWMM@MnzzznxW       @M+;;;*i;;;;;;i*xxM*iiiii+*iii.............,+MWniii**+xMn++++z+x@               W iiiii*xz n@     x********x"
	@echo "   Wx+++ ;;;;;;+iiii+M@    zzzznM@ WMxnMMMMxM ;;;+iiiiiii*xxniiiii*ziii*..............*W Mn++++  nnz+++z+n@               Wx*iiii+nn+x@    ni******** "
	@echo "   Mz ++ ;;;;;i*iiiin@     zzzxx @nxxnznnzzzzn+;;i iiiiiiizMziiiiinxiiii..............:n@ Wx ++ + nx+++z+xW                M*iiiizWx M    W*i********n"
	@echo "  Mn    +;;;;;+;iii M      xznMWMxxnzznnznnnnnn+ii*+iiiiii+M+iiii*xx+*ii...............nM  nn   +++zz++z+W                 W+iiiizxx W     ii*******iW"
	@echo " @n +   +;;;;*i;ii*x@     @xnxxnxnznzzzzzzzznznx*ii**iiiiiin+iiiizWW i*;............... M   Mn++  ++ z+  W                 W+iiiiz@WzM    i;i*******x "
	@echo " @n+++ z+;;;;+;iiizM      xMMzMnzzzzzzzzzzzznnnzn*iiiiiiiii* iiiiz@x i*,...............;W    Mzz  +++++ +W                 x iiiiM Mn@    *;i***** W  "
	@echo "@x  + nx*;;;ii;ii*x         xMnnzzzzzzzzzzzzn+ nnziiiiiiiiii*+ii+MWz i+................,n@    WMnn ++++ +M@                Mziiiix@xxM    +;;*****W   "
	@echo "Mn  nMWx**;;;;;ii W        xMnzzzzzzzzznznnzzz;znnziiiiiiiiii**iinnx+i*................. x      WMxz ++  M@                @niiiinWWx@    ni;;*+*z    "
	@echo "W +zM@ M M+;;;;i*M        WMnzzzzznnnzznznnnzn;;znn+iiiiiiiiii**i*nni*i.................*M         xx   +nM                @n*iiin@       Wi;;i**n    "
	@echo "x+zMW  @WMzi;;;izM        xnnzz zzznnzznznnzzni;;zzn*iiiiiiiiii *i*zi+,.................:M          WMz+zzn@@               W+iii W         i;;iiW    "
	@echo "n x      Mx;;;i*n@       xnnz     znzzzzzznzzn*;;ixnn*iii**iiiii+ii*++..................,x           @nni+ nM               W+iiinW        zi;;;*@    "
	@echo "nx@      @x;;;;zW        xzn    ++  nzzznnnnnn+;;;inznz*ii++*iiiiiii+i...................zW           @Mi+*M@               @ iiiM        W*;;;;*@    "
	@echo "@@       W ;;;iM@       WM n +++****znznnznnzz ;;;;in  nn ii +*iii*;i+,................,.+@            Wz nx                W iiiM@        i;;;;iW    "
	@echo "         W*;;; M        @n   +*iiiiii nnnnz   z;;;;;in   znz*i+ +;+;;i*................,.*M             MxMM                W iiiW      W *ii;;;iz    "
	@echo "         Wi;;;x@        @z** *iiiiiiii*nxzzz  z;;;;iiizz    xz+i*+++;;*;.........,,,,,,,.;@             @W@                 Wzii*x    @z****i;;i**M   "
	@echo "         x;;;+W         @zii+iiiiiiiiii*zz    n;;iiiiii nzzn*i+ *;;;;;;+,....,,,,,,,,,...:M                                 n ii*x  @n*******i;i***@  "
	@echo "        W ;;;n@         Wzi:iiiiiiiiiiiii*znzz ;iiiiiiii*zziiiii+ *;;;;ii.,,..............M                                 Mzii+M   *********ii***n  "
	@echo "        M+;;in@         @n;.,+iiiiiiiiiiiiii++iiiiiiii*  i;iiiiii*+ ;;;;+,,...............n                                 @zii @ n*********+*i***   "
	@echo "        Mi;;zW           x:..i*iiiiiiiiiiiiiiiiiiiiii+ i;;iiiiiii*.++;;;i+,...............xMW                               @niizx@*******+**+*ii**z  "
	@echo "       Wn;;;x@          @M,...+iiiiiiiiiiiiiiiiiiii*z*;;;;iiii**+,., +**;*i.,.............zxxM                              @ziiz@n****+++++*+*ii**z  "
	@echo "       Mz;;*x            Mi...,+*iiiiiiiiiiiiiiiii* i;;;;iiiii* i...;'+.';.i..............*nzxn@                            Wziin n***++++++++*i*+*z  "
	@echo "       x*;;zM            @ ....,**iiiiiiiiiiiiiii* ii;;;;iiiiii ,..,;,*,'*i*,.............*zzznxn                           W i+M n***+*++*ii*ii*+*W  "
	@echo "      @xi;iz              x:,....;+iiiiiiiiiiiiii *i;;;;iiiiiii+....i;.;,;................i*nzzznxnW@                       @+;zW  ***i;i*iiiii*+++   "
	@echo "      @n;;*M              Mn,.....,**iiiiiiiiiii+*ii;;;iiiiiiii+....;..;*.................*izzzzzznxnxM@MM W@               M*ix@ +**iiiiiiiiii*+*n   "
	@echo "      W ;; M               Wi,,,..,,:++iiiiiiiii iii;;iiiiiiiii+........,.................+i*nzzzzzzzzznnnxnMW              Wi+x  +*iiiiiiiiiii**z    "
	@echo "      M+;;nW               Wz;,,......;++*iiiii *ii;;;iiiiiiiii+,.........................+iizzzzzzzzzzzzznzM              @MinW  n*iiii;ii**** M     "
	@echo "      W*;;z@                Mz;,........,i++*i* iii;;iiiiiiiiii+:......................... ii*nzzzzzzzzznxxnMn znxM@       @x*x   niii;;;i*+++n       "
	@echo "      @i;iM                  Mz;,..........,i+z*iii;;iiiiiiiiii+:........................:*iii+xnzzzzzzzzzzzzzzzzxn@  W@   @nzM  M*i;;;;;i++*x        "
	@echo "      @*;iM                   M ;:............+iii;;iiiiiiiiiii*;........................*iiiii+nnnzzzzzzzzzzzzzxx nxxnxM   Mx  @*;;;;;;;i+*          "
	@echo "      W*;*n                   @ +i;,.........:+iii;;iiiiiiiiiii*i........................+iiiiii   nnzzzzzzzzzzxzzzzzzxx@   WW  ni;;;;;;;***@         "
	@echo "      x+;+W                    @W ii;,.......*iiii;iiiiiiiiiiiiii.......................;*iiiiiiiz   znnzzzzzzzzzzzznxxnnW@ @x@Wx+ +*;;;i**M          "
	@echo "      @ ; W                     WMziii;,.....+iiiiiiiiiiiiiiiiii*.......................*iiiiiiiiizznz  znnnzzzzzzzznzzzzz+***iii;*+*;;i**x           "
	@echo "      Mz; x                       Wn*iii;:,,. iiiiiiiiiiiiiiiiii*......................i*iiiiiiii;ixWnWnnnzzznnxnzzzzzzzzz+ii**   *;;;i*+M            "
	@echo "      @z; M                        MM+iiiii;; iiiiiiiiiiiiiiiiii*.....................,+iiiiiiiii;;+W  @@WWMMnxxnxxxMMMxxxn MxWM@WWxxxxM@             "
	@echo "       Mi @                         Wxz*iiii* *iiiiiiiiiiiiiiiii*....................,**iiiiiiii;;;;zW         @W@@W  W                               "
	@echo "       M +@                           xx+iii  +*iiii;;;;iiiiiii*i.................,,:+ *iiiiiiiii;;;iM@                                               "
	@echo "       @n+x                            Wxz**nz++*iii;;;;;iiiiii+:.............,,:;;i*z+++*iiiiiiii;;;nW                                               "
	@echo "        xnW                              WMz z+++*ii;;;;;iiiiii ;;:::,,,,,::;;iiiii*z++++++*iiiiiiiii+W                                               "
	@echo "                                        @Mn  z++++*ii;;;iiiiii* iiiiiiiiiiiiiiiiii* +++++  ++*iiiiiii*x                                               "
	@echo "                                        @n+++z+++++*i;;iiiiiiiziiiiiiiiiiiiiiiiii z++  ++  ++++**iiii*W                                               "
	@echo "                                       xn    n++++ +*iii*****z+iiiiiiiiiiiiiiii*znn   +++    + ++****+n                                               "
	@echo "                                       M ++++n++++z ++++++ +  iiiiiiiiiiiiiii*nMzzzn    ++   + ++++++ W                                               "
	@echo "                                      Wn+++++  +++ ++++ + z  iiiiiiiiiiiiii+zxWMnzzzn         + ++   zW                                               "
	@echo "                                      xz+++++  +++++ ++  zzziiiiiiiiiii*+znMW  @Wzzzzn +   ++++++ +++nx                                               "
	@echo "                                     @x  +++++ + ++   ++ zMWM+zz   +   MxW      xxzzzzz   +++++++++++xW                                               "
	@echo "                                     Mn       +++z ++  zMn@  @@      @@         @Mzzzzzz  ++++++++++zx                                                "
	@echo "                                     Wz++     +++ xn zxMW                        Mnzzzzz   z ++ + zxW                                                 "
	@echo "                                    @z +++++++++  MWMM@                          WxzzzzzzzzzxxzznnMW                                                  "
	@echo "                                    @x++++++++++ zn                               MzzzzzzzzznxMW@@                                                    "
	@echo "                                    Wn +++++++++ n@                               xnzzzzzzzzzM@                                                       "
	@echo "                                    Mz +  +  +   nW                               MnzzzzzzzzzxW                                                       "
	@echo "                                    W  ++ +++++++zM                               MxzzzzzzzzznMnM                                                     "
	@echo "                                    M++********++zM                               @xzzzznnzzzzzzznx                                                   "
	@echo "                                    xiiiiiiiiiii*z@                               @xzzzzn+znn*i* * xM                                                 "
	@echo "                                   Wziiiiiiiiiiii M                                xnzzzz+++zi;;;+**nM                                                "
	@echo "                                   @xiiii;;i**ii+zM                                MMnzn +**i+*i;;*xMM                                                "
	@echo "                                   Mzii**i;*:**i*,z@                                @WMnnxnz+*zxxx+xM                                                 "
	@echo "                                   Wn**:'*;*'.++, :n@                                  @@  @WxWM                                                      "
	@echo "                                    M+*' ;*.''i    *n                                                                                                 "
	@echo "                                    Wn:  '+'  'z:' '+W                                                                                                "
	@echo "                                    @M+.  +i'  *zn :,z@                                                                                               "
	@echo "                                      M *.iMn+,.x@@nxxM                                                                                               "
	@echo "                                       @@xz@@Mxzn@                                                                                                    $'[0m"
