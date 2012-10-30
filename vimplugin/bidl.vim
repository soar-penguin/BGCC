" Vim syntax file
" Language:	bidl
" Maintainer:	liuxupeng<liuxupeng@baidu.com>
" Last Change:	2012 Oct 23

if exists("b:current_syntax")
  finish
endif

syn keyword	cStatement	namespace const in out all typedef
syn keyword	cStructure	struct enum class
syn keyword	cType 		void boolean int8 int16 int32 int64 float string binary
syn keyword	cType		map sequence set
syn keyword	cConstant	true TRUE false FALSE

syn keyword cReservedError  _CLASS__	__DIR__	__FILE__	__LINE__	__METHOD__	__NAMESPACE__	abstract
syn keyword cReservedError  alias	alignas	alignof	and	and_eq	args	as
syn keyword cReservedError  asm	assert	auto	BEGIN	bitand	bitor	bool
syn keyword cReservedError  break	byte	case	catch	char	char16_t	char32_t
syn keyword cReservedError  clone	compl	const_cast	constexpr	continue	cpp	cpp_type
syn keyword cReservedError  declare	decltype	def	default	del	delete	do
syn keyword cReservedError  double	dynamic	dynamic_cast	elif	else	elseif	elsif
syn keyword cReservedError  END	enddeclare	endfor	endforeach	endif	endswitch	endwhile
syn keyword cReservedError  ensure	except	exec	explicit	export	extends	extern
syn keyword cReservedError  final	finally	for	foreach	friend	function	global
syn keyword cReservedError  goto	if	implements	import	inline	instanceof	int
syn keyword cReservedError  interface	is	java	lambda	long	module	mutable
syn keyword cReservedError  native	new	next	nil	noexcept	not	not_eq
syn keyword cReservedError  null	nullptr 	operator	optional	or	or_eq	package
syn keyword cReservedError  pass	print	private	protected	protocol	public	raise
syn keyword cReservedError  redo	register	reinterpret_cast	request	request_len	required	rescue
syn keyword cReservedError  retry	return	self	short	signed	sizeof	static
syn keyword cReservedError  static_assert	static_cast	strictfp	super	switch	synchronized	template
syn keyword cReservedError  then	this	thread_local	throw	throws	transient	try
syn keyword cReservedError  typeid	typename	undef	union	unless	unsigned	until
syn keyword cReservedError  use	using	var	virtual	volatile	wchar_t	when
syn keyword cReservedError  while	with	xor	xor_eq	yield		

syn region	cCppString	start=+L\="+ skip=+\\\\\|\\"\|\\$+ excludenl end=+"+ end='$'

syn match	cNumbers	display transparent "\<\d\|\.\d" contains=cNumber,cFloat
syn match	cNumber		display contained "\d\+\(u\=l\{0,2}\|ll\=u\)\>"
syn match	cFloat		display contained "\d\+f"
syn match	cFloat		display contained "\d\+\.\d*\(e[-+]\=\d\+\)\=[fl]\="
syn match	cFloat		display contained "\.\d\+\(e[-+]\=\d\+\)\=[fl]\=\>"
syn match	cFloat		display contained "\d\+e[-+]\=\d\+[fl]\=\>"

syn region	cCommentL	start="//" skip="\\$" end="$" keepend
syn region	cComment	matchgroup=cCommentStart start="/\*" end="\*/" fold extend
syntax match	cCommentError	display "\*/"

syn region	cIncluded	display contained start=+"+ skip=+\\\\\|\\"+ end=+"+
syn match	cInclude	display "^\s*include\>\s*["<]" contains=cIncluded

hi def link cCppString		String
hi def link cCommentL		cComment
hi def link cCommentStart	cComment
hi def link cNumber		Number
hi def link cFloat		Float
hi def link cCommentError	Error
hi def link cReservedError	Error
hi def link cStructure		Structure
hi def link cInclude		Include
hi def link cIncluded		String
hi def link cStatement		Statement
hi def link cType		Type
hi def link cConstant		Constant
hi def link cString		String
hi def link cComment		Comment

let b:current_syntax = "bidl"

" vim: ts=4
