#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

export LIGHTYEAR_PATH=$HOME/git/work/lightyear-firmware

alias ls='ls --color=auto'

alias lemdev='. $LIGHTYEAR_PATH/export.sh'

alias idf_33='. $HOME/switch_idf.sh 3.3'
alias idf_40='. $HOME/switch_idf.sh 4.0'
alias idf_41='. $HOME/switch_idf.sh 4.1'
alias idf_42='. $HOME/switch_idf.sh 4.2'
alias idf_00='. $HOME/switch_idf.sh 0.0'

alias cdw='cd $HOME/git/work'
alias adv='cd $HOME/git/home/adventure3d'

alias flash='make -j9 flash monitor'

PS1='[\u@\h \W]\$ '

[ -f ~/.fzf.bash ] && source ~/.fzf.bash

wal-scale() {
    wal -n -i "$@"
    nitrogen --set-scaled --head=0 "$(< "${HOME}/.cache/wal/wal")"
    nitrogen --set-scaled --head=1 "$(< "${HOME}/.cache/wal/wal")"
}

(cat ~/.cache/wal/sequences &)

BASEPATH=$PATH
