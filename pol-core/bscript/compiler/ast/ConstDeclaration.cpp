#include "ConstDeclaration.h"


#include <utility>

#include "bscript/compiler/ast/Expression.h"
#include "bscript/compiler/ast/NodeVisitor.h"

namespace Pol::Bscript::Compiler
{
ConstDeclaration::ConstDeclaration( const SourceLocation& source_location, std::string identifier,
                                    std::unique_ptr<Expression> expression,
                                    bool ignore_overwrite_attempt )
    : Node( source_location, std::move( expression ) ),
      identifier( std::move( identifier ) ),
      ignore_overwrite_attempt( ignore_overwrite_attempt )
{
}

Expression& ConstDeclaration::expression()
{
  return child<Expression>( 0 );
}

void ConstDeclaration::accept( NodeVisitor& visitor )
{
  visitor.visit_const_declaration( *this );
}

void ConstDeclaration::describe_to( std::string& w ) const
{
  fmt::format_to( std::back_inserter( w ), "const-declaration({})", identifier );
}

}  // namespace Pol::Bscript::Compiler
