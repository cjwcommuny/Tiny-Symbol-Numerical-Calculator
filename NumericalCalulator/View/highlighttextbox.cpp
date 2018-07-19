#include "highlighttextbox.h"
//#include "ui_HighlightTextBox.h"

HighlightTextBox::HighlightTextBox(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    keywordFormat.setForeground(Qt::darkBlue);
    keywordFormat.setFontWeight(QFont::Bold);
    QStringList keywordPatterns;
    keywordPatterns << "\\bDraw\\b"
                    << "\\bComputeDeterminant\\b"
                    << "\\bSolvePoly\\b"
                    << "\\binvert\\b"
                    << "\\btranspose\\b";
    foreach (const QString &pattern, keywordPatterns) {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    HighlightingRule numberRule;
    numberFormat.setForeground(Qt::red);
    numberFormat.setFontItalic(true);
    numberRule.pattern = QRegularExpression("[0-9]{1,30}");
    numberRule.format = numberFormat;
    highlightingRules.append(numberRule);
}

HighlightTextBox::~HighlightTextBox()
{
    
}

void HighlightTextBox::highlightBlock(const QString &text)
{
    foreach (const HighlightingRule &rule, highlightingRules) {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while (matchIterator.hasNext()) {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
    setCurrentBlockState(0);
}

void HighlightTextBox::setTextQueue(const QStringList& textQueue)
{
    highlightingRules.clear();
    HighlightingRule rule;

    const QString tmp("\\b");
    foreach(const QString& str,textQueue)
    {   
        QString pattern(tmp);
        pattern += str;
        pattern += tmp;
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
}
