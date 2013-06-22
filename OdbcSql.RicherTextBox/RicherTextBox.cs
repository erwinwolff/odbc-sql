using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace OdbcSql.RicherTextBox
{
    /// <summary>
    /// Simple overload of classic RtfTextbox
    /// </summary>
    public class RicherTextBox : RichTextBox
    {

        public RicherTextBox()
            : base()
        {
            //--
        }

        public void initRicherTextbox()
        {
            string colortable = @"{\rtf1\ansi{\colortbl;\red0\green0\blue255;} \cf1 \n\n\par}";
            this.Rtf = colortable;
        }


        private List<string> _systemKeywords = new List<string>()
        {
            "@@dsn",
            "@@drivers"
        };

        /// <summary>
        /// All SQL and ODBC reserved keywords
        /// </summary>
        private List<string> _sqlKeywords = new List<string>()
        {
            "add",
            "except",
            "percent",
            "all",
            "exec",
            "plan",
            "alter",
            "execute",
            "precision",
            "and",
            "exists",
            "primary",
            "any",
            "exit",
            "print",
            "as",
            "fetch",
            "proc",
            "asc",
            "file",
            "procedure",
            "authorization",
            "fillfactor",
            "public",
            "backup",
            "for",
            "raiserror",
            "begin",
            "foreign",
            "read",
            "between",
            "freetext",
            "readtext",
            "break",
            "freetexttable",
            "reconfigure",
            "browse",
            "from",
            "references",
            "bulk",
            "full",
            "replication",
            "by",
            "function",
            "restore",
            "cascade",
            "goto",
            "restrict",
            "case",
            "grant",
            "return",
            "check",
            "group",
            "revoke",
            "checkpoint",
            "having",
            "right",
            "close",
            "holdlock",
            "rollback",
            "clustered",
            "identity",
            "rowcount",
            "coalesce",
            "identity_insert",
            "rowguidcol",
            "collate",
            "identitycol",
            "rule",
            "column",
            "if",
            "save",
            "commit",
            "in",
            "schema",
            "compute",
            "index",
            "select",
            "constraint",
            "inner",
            "session_user",
            "contains",
            "insert",
            "set",
            "containstable",
            "intersect",
            "setuser",
            "continue",
            "into",
            "shutdown",
            "convert",
            "is",
            "some",
            "create",
            "join",
            "statistics",
            "cross",
            "key",
            "system_user",
            "current",
            "kill",
            "table",
            "current_date",
            "left",
            "textsize",
            "current_time",
            "like",
            "then",
            "current_timestamp",
            "lineno",
            "to",
            "current_user",
            "load",
            "top",
            "cursor",
            "national",
            "tran",
            "database",
            "nocheck",
            "transaction",
            "dbcc",
            "nonclustered",
            "trigger",
            "deallocate",
            "not",
            "truncate",
            "declare",
            "null",
            "tsequal",
            "default",
            "nullif",
            "union",
            "delete",
            "of",
            "unique",
            "deny",
            "off",
            "update",
            "desc",
            "offsets",
            "updatetext",
            "disk",
            "on",
            "use",
            "distinct",
            "open",
            "user",
            "distributed",
            "opendatasource",
            "values",
            "double",
            "openquery",
            "varying",
            "drop",
            "openrowset",
            "view",
            "dummy",
            "openxml",
            "waitfor",
            "dump",
            "option",
            "when",
            "else",
            "or",
            "where",
            "end",
            "order",
            "while",
            "errlvl",
            "outer",
            "with",
            "escape",
            "over",
            "writetext",
            "absolute",
            "exec",
            "overlaps",
            "action",
            "execute",
            "pad",
            "ada",
            "exists",
            "partial",
            "add",
            "external",
            "pascal",
            "all",
            "extract",
            "position",
            "allocate",
            "false",
            "precision",
            "alter",
            "fetch",
            "prepare",
            "and",
            "first",
            "preserve",
            "any",
            "float",
            "primary",
            "are",
            "for",
            "prior",
            "as",
            "foreign",
            "privileges",
            "asc",
            "fortran",
            "procedure",
            "assertion",
            "found",
            "public",
            "at",
            "from",
            "read",
            "authorization",
            "full",
            "real",
            "avg",
            "get",
            "references",
            "begin",
            "global",
            "relative",
            "between",
            "go",
            "restrict",
            "bit",
            "goto",
            "revoke",
            "bit_length",
            "grant",
            "right",
            "both",
            "group",
            "rollback",
            "by",
            "having",
            "rows",
            "cascade",
            "hour",
            "schema",
            "cascaded",
            "identity",
            "scroll",
            "case",
            "immediate",
            "second",
            "cast",
            "in",
            "section",
            "catalog",
            "include",
            "select",
            "char",
            "index",
            "session",
            "char_length",
            "indicator",
            "session_user",
            "character",
            "initially",
            "set",
            "character_length",
            "inner",
            "size",
            "check",
            "input",
            "smallint",
            "close",
            "insensitive",
            "some",
            "coalesce",
            "insert",
            "space",
            "collate",
            "int",
            "sql",
            "collation",
            "integer",
            "sqlca",
            "column",
            "intersect",
            "sqlcode",
            "commit",
            "interval",
            "sqlerror",
            "connect",
            "into",
            "sqlstate",
            "connection",
            "is",
            "sqlwarning",
            "constraint",
            "isolation",
            "substring",
            "constraints",
            "join",
            "sum",
            "continue",
            "key",
            "system_user",
            "convert",
            "language",
            "table",
            "corresponding",
            "last",
            "temporary",
            "count",
            "leading",
            "then",
            "create",
            "left",
            "time",
            "cross",
            "level",
            "timestamp",
            "current",
            "like",
            "timezone_hour",
            "current_date",
            "local",
            "timezone_minute",
            "current_time",
            "lower",
            "to",
            "current_timestamp",
            "match",
            "trailing",
            "current_user",
            "max",
            "transaction",
            "cursor",
            "min",
            "translate",
            "date",
            "minute",
            "translation",
            "day",
            "module",
            "trim",
            "deallocate",
            "month",
            "true",
            "dec",
            "names",
            "union",
            "decimal",
            "national",
            "unique",
            "declare",
            "natural",
            "unknown",
            "default",
            "nchar",
            "update",
            "deferrable",
            "next",
            "upper",
            "deferred",
            "no",
            "usage",
            "delete",
            "none",
            "user",
            "desc",
            "not",
            "using",
            "describe",
            "null",
            "value",
            "descriptor",
            "nullif",
            "values",
            "diagnostics",
            "numeric",
            "varchar",
            "disconnect",
            "octet_length",
            "varying",
            "distinct",
            "of",
            "view",
            "domain",
            "on",
            "when",
            "double",
            "only",
            "whenever",
            "drop",
            "open",
            "where",
            "else",
            "option",
            "with",
            "end",
            "or",
            "work",
            "end-exec",
            "order",
            "write",
            "escape",
            "outer",
            "year",
            "except",
            "output",
            "zone",
            "exception"
        };

        /// <summary>
        /// 
        /// </summary>
        /// <param name="text"></param>
        public new void AppendText(string text)
        {
            text = text.Replace("\r", string.Empty);
            text = text.Replace("\n", "\\par");

            text = text.Replace("\t", "\\tab");

            this.AppendRtf(text);
        }


        /// <summary>
        /// Adds rtf formatted code
        /// </summary>
        /// <param name="rtf">Valid(!!) RTF code</param>
        public void AppendRtf(string rtf)
        {
            if (!rtf.EndsWith(@"\par"))
            {
                rtf += @"\par";
            }


            string contents = this.Rtf;
            int last = contents.LastIndexOf(@"\par");
            contents = contents.Insert(last - 1, rtf);

            this.Rtf = contents;
        }

        /// <summary>
        /// Do some syntax highlightning
        /// </summary>
        /// <param name="sql"></param>
        /// <returns>RTF formatted SQL code</returns>
        public string HighlightSQL(string sql)
        {
            sql = sql.Replace("\r", string.Empty);
            sql = sql.Replace("\n", string.Empty);

            string[] keywords = sql.Split(" ".ToCharArray());
            string result = string.Empty;

            for (int i = 0; i < keywords.Length; i++)
            {
                if (_sqlKeywords.Contains(keywords[i].ToLower()))
                {
                    keywords[i] = @"\cf1" + keywords[i] + @" \cf0";
                }
            }

            result = string.Join(" ", keywords.ToArray());
            return result;
        }

        //public string HighlightSystemKeywords(string systemKeyword)
        //{
        //    List<string> keywords = systemKeyword.Split(" ".ToCharArray()).ToList();
        //    string result = string.Empty;

        //    for (int i = 0; i < keywords.Count; i++)
        //    {
        //        if (_systemKeywords.Contains(keywords[i].ToLower()))
        //        {
        //            keywords[i] = @"\cf2" + keywords[i] + @" \cf0";
        //        }
        //    }

        //    result = string.Join(" ", keywords.ToArray());
        //    return result;
        //}


    }
}
