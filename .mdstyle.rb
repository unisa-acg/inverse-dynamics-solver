# Refer to https://github.com/markdownlint/markdownlint/blob/main/docs/RULES.md
all

# This allows for a correct visualization on BitBucket
rule 'MD007', indent: 4 # Unordered list indentation

# This allows for a correct numbering on BitBucket
rule 'MD029', style: "ordered" # Ordered list item prefix

# We exclude maximum line length as we agreed in the past to use newlines after main punctuation characters such as (semi-)colon or full stops.
# At the moment we don't have a rule to enforce newlines at every fullstop but this may be considered in the future
exclude_rule 'MD013' # Line length
