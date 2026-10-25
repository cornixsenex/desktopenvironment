#
# ~/.bash_profile
#

[[ -f ~/.bashrc ]] && . ~/.bashrc


if [[ ! $DISPLAY && $XDG_VTNR -eq 1 ]]; then
	  exec startx
fi


# Added by LM Studio CLI (lms)
export PATH="$PATH:/home/qwe/.cache/lm-studio/bin"
