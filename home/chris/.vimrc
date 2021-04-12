call plug#begin('~/.vim/plugs')

Plug 'scrooloose/nerdtree'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'powerline/powerline'
Plug 'fatih/vim-go'
Plug 'Valloric/YouCompleteMe'
Plug 'junegunn/fzf', {'dir': '~/.fzf', 'do': './install --all' }
Plug 'mileszs/ack.vim'
Plug 'morhetz/gruvbox'
Plug 'vim-scripts/turbo.vim'
Plug 'dracula/vim', { 'as': 'dracula' }
Plug 'tomasr/molokai'
Plug 'godlygeek/tabular'
Plug 'ycm-core/YouCompleteMe'
Plug 'tikhomirov/vim-glsl'
Plug 'udalov/kotlin-vim'
Plug 'dylanaraps/wal.vim'

call plug#end()

" color settings
set background=dark
color molokai
"color wal

" mapping
nnoremap <F2>  :NERDTree ~/git<CR>
nnoremap <F4>  :bp!<bar>sp!<bar>bn!<bar>bd!<CR>
nnoremap <F6>  :%!xxd<CR>
nnoremap <F7>  :%!xxd -r<CR>
nnoremap <C-H> :bp<CR>
nnoremap <C-L> :bn<CR>
nnoremap <F3>  :let @/=""<CR>
nnoremap <C-P> :FZF<CR>

"misc settings
set cursorline
set showcmd
set ruler
set incsearch
set wildmode=longest,list,full
set wildmenu
set synmaxcol=0
set number relativenumber
set mouse=a
syntax enable

set diffopt+=iwhite
set scrolloff=999
set ignorecase
set smartcase
set nowritebackup

set completeopt=menu
set mousemodel=popup
set backspace=2
set number
set nocompatible
set enc=utf-8

set expandtab
set tabstop=4
set shiftwidth=4
set foldcolumn=1

set linespace=0
set history=1000

set laststatus=2
set wrap
set nopaste

set rtp+=~/.fzf
set clipboard=unnamed

let g:airline#extensions#tabline#enabled = 1
let g:airline#extensions#tabline#fnamemod = ':t'
let g:airline_powerline_fonts = 1

let g:clipboard = {
\   'name': 'xclip-xfce4-clipman',
\   'copy': {
\      '+': 'xclip -selection clipboard',
\      '*': 'xclip -selection clipboard',
\    },
\   'paste': {
\      '+': 'xclip -selection clipboard -o',
\      '*': 'xclip -selection clipboard -o',
\   },
\   'cache_enabled': 1,
\ }

" Ctrl-P
let g:ctrlp_map = '<c-0>'
let g:ctrlp_cmd = 'CtrlP'
let g:ctrlp_working_path_mode = 'ra'

if !exists('g:airline_symbols')
  let g:airline_symbols = {}
endif
" This is the default extra key bindings
let g:fzf_action = {
  \ 'ctrl-t': 'tab split',
  \ 'ctrl-x': 'split',
  \ 'ctrl-v': 'vsplit' }

" An action can be a reference to a function that processes selected lines
function! s:build_quickfix_list(lines)
  call setqflist(map(copy(a:lines), '{ "filename": v:val }'))
  copen
  cc
endfunction

let g:fzf_action = {
  \ 'ctrl-q': function('s:build_quickfix_list'),
  \ 'ctrl-t': 'tab split',
  \ 'ctrl-x': 'split',
  \ 'ctrl-v': 'vsplit' }

" Default fzf layout
" - down / up / left / right
let g:fzf_layout = { 'down': '~40%' }

" You can set up fzf window using a Vim command (Neovim or latest Vim 8 required)
let g:fzf_layout = { 'window': 'enew' }
let g:fzf_layout = { 'window': '-tabnew' }
let g:fzf_layout = { 'window': '10split enew' }

let g:ackprg = 'ag --vimgrep'

" Customize fzf colors to match your color scheme
let g:fzf_colors =
\ { 'fg':      ['fg', 'Normal'],
  \ 'bg':      ['bg', 'Normal'],
  \ 'hl':      ['fg', 'Comment'],
  \ 'fg+':     ['fg', 'CursorLine', 'CursorColumn', 'Normal'],
  \ 'bg+':     ['bg', 'CursorLine', 'CursorColumn'],
  \ 'hl+':     ['fg', 'Statement'],
  \ 'info':    ['fg', 'PreProc'],
  \ 'border':  ['fg', 'Ignore'],
  \ 'prompt':  ['fg', 'Conditional'],
  \ 'pointer': ['fg', 'Exception'],
  \ 'marker':  ['fg', 'Keyword'],
  \ 'spinner': ['fg', 'Label'],
  \ 'header':  ['fg', 'Comment'] }

" Enable per-command history.
" CTRL-N and CTRL-P will be automatically bound to next-history and
" previous-history instead of down and up. If you don't like the change,
" explicitly bind the keys to down and up in your $FZF_DEFAULT_OPTS.
let g:fzf_history_dir = '~/.local/share/fzf-history'

let g:gitgutter_terminal_reports_focus=0
