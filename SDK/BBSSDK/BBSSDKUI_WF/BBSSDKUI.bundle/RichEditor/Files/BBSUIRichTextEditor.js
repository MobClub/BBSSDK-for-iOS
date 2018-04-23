
var bbsui_editor = {};

// If we are using iOS or desktop
bbsui_editor.isUsingiOS = true;

// If the user is draging
bbsui_editor.isDragging = false;

// The current selection
bbsui_editor.currentSelection;

// The current editing image
bbsui_editor.currentEditingImage;

// The current editing link
bbsui_editor.currentEditingLink;

// The objects that are enabled
bbsui_editor.enabledItems = {};

// Height of content window, will be set by viewController
bbsui_editor.contentHeight = 244;

// Sets to true when extra footer gap shows and requires to hide
bbsui_editor.updateScrollOffset = false;

/**
 * The initializer function that must be called onLoad
 */
bbsui_editor.init = function() {
    
    $('#bbsui_editor_content').on('touchend', function(e) {
                                bbsui_editor.enabledEditingItems(e);
                                var clicked = $(e.target);
                                if (!clicked.hasClass('zs_active')) {
                                $('img').removeClass('zs_active');
                                }
                                });
    
    $(document).on('selectionchange',function(e){
                   bbsui_editor.calculateEditorHeightWithCaretPosition();
                   bbsui_editor.setScrollPosition();
                   bbsui_editor.enabledEditingItems(e);
                   });
    
    $(window).on('scroll', function(e) {
                 bbsui_editor.updateOffset();
                 });
    
    // Make sure that when we tap anywhere in the document we focus on the editor
    $(window).on('touchmove', function(e) {
                 bbsui_editor.isDragging = true;
                 bbsui_editor.updateScrollOffset = true;
                 bbsui_editor.setScrollPosition();
                 bbsui_editor.enabledEditingItems(e);
                 });
    $(window).on('touchstart', function(e) {
                 bbsui_editor.isDragging = false;
                 });
    $(window).on('touchend', function(e) {
                 if (!bbsui_editor.isDragging && (e.target.id == "bbsui_editor_footer"||e.target.nodeName.toLowerCase() == "html")) {
                 bbsui_editor.focusEditor();
                 }
                 });
    
}//end

bbsui_editor.updateOffset = function() {
    
    if (!bbsui_editor.updateScrollOffset)
        return;
    
    var offsetY = window.document.body.scrollTop;
    
    var footer = $('#bbsui_editor_footer');
    
    var maxOffsetY = footer.offset().top - bbsui_editor.contentHeight;
    
    if (maxOffsetY < 0)
        maxOffsetY = 0;
    
    if (offsetY > maxOffsetY)
    {
        window.scrollTo(0, maxOffsetY);
    }
    
    bbsui_editor.setScrollPosition();
}

// This will show up in the XCode console as we are able to push this into an NSLog.
bbsui_editor.debug = function(msg) {
    window.location = 'debug://'+msg;
}


bbsui_editor.setScrollPosition = function() {
    var position = window.pageYOffset;
    window.location = 'scroll://'+position;
}


bbsui_editor.setPlaceholder = function(placeholder) {
    
    var editor = $('#bbsui_editor_content');
    
    //set placeHolder
	editor.attr("placeholder",placeholder);
	
    //set focus			 
	editor.focusout(function(){
        var element = $(this);        
        if (!element.text().trim().length) {
//            element.empty(); // 必须注释 否则后果自负。
        }
    });
	
	
    
}

bbsui_editor.setFooterHeight = function(footerHeight) {
    var footer = $('#bbsui_editor_footer');
    footer.height(footerHeight + 'px');
}

bbsui_editor.getCaretYPosition = function() {
    var sel = window.getSelection();
    // Next line is comented to prevent deselecting selection. It looks like work but if there are any issues will appear then uconmment it as well as code above.
    //sel.collapseToStart();
    var range = sel.getRangeAt(0);
    var span = document.createElement('span');// something happening here preventing selection of elements
    range.collapse(false);
    range.insertNode(span);
    var topPosition = span.offsetTop;
    span.parentNode.removeChild(span);
    return topPosition;
}

bbsui_editor.calculateEditorHeightWithCaretPosition = function() {
    
    var padding = 50;
    var c = bbsui_editor.getCaretYPosition();
    
    var editor = $('#bbsui_editor_content');
    
    var offsetY = window.document.body.scrollTop;
    var height = bbsui_editor.contentHeight;
    
    var newPos = window.pageYOffset;
    
    if (c < offsetY) {
        newPos = c;
    } else if (c > (offsetY + height - padding)) {
        newPos = c - height + padding - 18;
    }
    
    window.scrollTo(0, newPos);
}

bbsui_editor.backuprange = function(){
    var selection = window.getSelection();
    var range = selection.getRangeAt(0);
    bbsui_editor.currentSelection = {"startContainer": range.startContainer, "startOffset":range.startOffset,"endContainer":range.endContainer, "endOffset":range.endOffset};
}

bbsui_editor.restorerange = function(){
    var selection = window.getSelection();
    selection.removeAllRanges();
    var range = document.createRange();
    range.setStart(bbsui_editor.currentSelection.startContainer, bbsui_editor.currentSelection.startOffset);
    range.setEnd(bbsui_editor.currentSelection.endContainer, bbsui_editor.currentSelection.endOffset);
    selection.addRange(range);
}

bbsui_editor.getSelectedNode = function() {
    var node,selection;
    if (window.getSelection) {
        selection = getSelection();
        node = selection.anchorNode;
    }
    if (!node && document.selection) {
        selection = document.selection
        var range = selection.getRangeAt ? selection.getRangeAt(0) : selection.createRange();
        node = range.commonAncestorContainer ? range.commonAncestorContainer :
        range.parentElement ? range.parentElement() : range.item(0);
    }
    if (node) {
        return (node.nodeName == "#text" ? node.parentNode : node);
    }
};

bbsui_editor.setBold = function() {
    document.execCommand('bold', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setItalic = function() {
    document.execCommand('italic', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setSubscript = function() {
    document.execCommand('subscript', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setSuperscript = function() {
    document.execCommand('superscript', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setStrikeThrough = function() {
    document.execCommand('strikeThrough', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setUnderline = function() {
    document.execCommand('underline', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setBlockquote = function() {
    document.execCommand('formatBlock', false, '<blockquote>');
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.removeFormating = function() {
    document.execCommand('removeFormat', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setHorizontalRule = function() {
    document.execCommand('insertHorizontalRule', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setHeading = function(heading) {
//    var current_selection = $(bbsui_editor.getSelectedNode());
//    var t = current_selection.prop("tagName").toLowerCase();
//    var is_heading = (t == 'h1' || t == 'h2' || t == 'h3' || t == 'h4' || t == 'h5' || t == 'h6');
//    if (is_heading && heading == t) {
//        var c = current_selection.html();
//        current_selection.replaceWith(c);
//    } else {
//        document.execCommand('formatBlock', false, '<'+heading+'>');
//    }
    
    var formatTag = heading;
    var formatBlock = document.queryCommandValue('formatBlock');
    
    if (formatBlock.length > 0 && formatBlock.toLowerCase() == formatTag) {
        document.execCommand('formatBlock', false, this.defaultParagraphSeparatorTag());
    } else {
        document.execCommand('formatBlock', false, '<' + formatTag + '>');
    }
    
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setParagraph = function() {
    var current_selection = $(bbsui_editor.getSelectedNode());
    var t = current_selection.prop("tagName").toLowerCase();
    var is_paragraph = (t == 'p');
    if (is_paragraph) {
        var c = current_selection.html();
        current_selection.replaceWith(c);
    } else {
        document.execCommand('formatBlock', false, '<p>');
    }
    
    bbsui_editor.enabledEditingItems();
}

// Need way to remove formatBlock
console.log('WARNING: We need a way to remove formatBlock items');

bbsui_editor.undo = function() {
    document.execCommand('undo', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.redo = function() {
    document.execCommand('redo', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setOrderedList = function() {
    document.execCommand('insertOrderedList', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setUnorderedList = function() {
    document.execCommand('insertUnorderedList', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setJustifyCenter = function() {
    document.execCommand('justifyCenter', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setJustifyFull = function() {
    document.execCommand('justifyFull', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setJustifyLeft = function() {
    document.execCommand('justifyLeft', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setJustifyRight = function() {
    document.execCommand('justifyRight', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setIndent = function() {
    document.execCommand('indent', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setOutdent = function() {
    document.execCommand('outdent', false, null);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setFontFamily = function(fontFamily) {

	bbsui_editor.restorerange();
	document.execCommand("styleWithCSS", null, true);
	document.execCommand("fontName", false, fontFamily);
	document.execCommand("styleWithCSS", null, false);
	bbsui_editor.enabledEditingItems();
		
}

bbsui_editor.setTextColor = function(color) {
		
    bbsui_editor.restorerange();
    document.execCommand("styleWithCSS", null, true);
    document.execCommand('foreColor', false, color);
    document.execCommand("styleWithCSS", null, false);
    bbsui_editor.enabledEditingItems();
    // document.execCommand("removeFormat", false, "foreColor"); // Removes just foreColor
	
}

bbsui_editor.setBackgroundColor = function(color) {
    bbsui_editor.restorerange();
    document.execCommand("styleWithCSS", null, true);
    document.execCommand('hiliteColor', false, color);
    document.execCommand("styleWithCSS", null, false);
    bbsui_editor.enabledEditingItems();
}

// Needs addClass method

bbsui_editor.insertLink = function(url, title) {
    
    bbsui_editor.restorerange();
    var sel = document.getSelection();
    console.log(sel);
    if (sel.toString().length != 0) {
        if (sel.rangeCount) {
            
            var el = document.createElement("a");
            el.setAttribute("href", url);
            el.setAttribute("title", title);
            
            var range = sel.getRangeAt(0).cloneRange();
            range.surroundContents(el);
            sel.removeAllRanges();
            sel.addRange(range);
        }
    }
    else
    {
        document.execCommand("insertHTML",false,"<a href='"+url+"'>"+title+"</a>");
    }
    
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.updateLink = function(url, title) {
    
    bbsui_editor.restorerange();
    
    if (bbsui_editor.currentEditingLink) {
        var c = bbsui_editor.currentEditingLink;
        c.attr('href', url);
        c.attr('title', title);
    }
    bbsui_editor.enabledEditingItems();
    
}//end

bbsui_editor.updateImage = function(url, alt) {
    
    bbsui_editor.restorerange();
    
    if (bbsui_editor.currentEditingImage) {
        var c = bbsui_editor.currentEditingImage;
        c.attr('src', url);
        c.attr('alt', alt);
    }
    bbsui_editor.enabledEditingItems();
    
}//end

bbsui_editor.updateImageBase64String = function(imageBase64String, alt) {
    
    bbsui_editor.restorerange();
    
    if (bbsui_editor.currentEditingImage) {
        var c = bbsui_editor.currentEditingImage;
        var src = 'data:image/jpeg;base64,' + imageBase64String;
        c.attr('src', src);
        c.attr('alt', alt);
    }
    bbsui_editor.enabledEditingItems();
    
}//end


bbsui_editor.unlink = function() {
    
    if (bbsui_editor.currentEditingLink) {
        var c = bbsui_editor.currentEditingLink;
        c.contents().unwrap();
    }
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.quickLink = function() {
    
    var sel = document.getSelection();
    var link_url = "";
    var test = new String(sel);
    var mailregexp = new RegExp("^(.+)(\@)(.+)$", "gi");
    if (test.search(mailregexp) == -1) {
        checkhttplink = new RegExp("^http\:\/\/", "gi");
        if (test.search(checkhttplink) == -1) {
            checkanchorlink = new RegExp("^\#", "gi");
            if (test.search(checkanchorlink) == -1) {
                link_url = "http://" + sel;
            } else {
                link_url = sel;
            }
        } else {
            link_url = sel;
        }
    } else {
        checkmaillink = new RegExp("^mailto\:", "gi");
        if (test.search(checkmaillink) == -1) {
            link_url = "mailto:" + sel;
        } else {
            link_url = sel;
        }
    }
    
    var html_code = '<a href="' + link_url + '">' + sel + '</a>';
    bbsui_editor.insertHTML(html_code);
    
}

bbsui_editor.prepareInsert = function() {
    bbsui_editor.backuprange();
}

bbsui_editor.insertImage = function(url, alt) {
    bbsui_editor.restorerange();
    var html = '<img src="'+url+'" alt="'+alt+'" />';
    bbsui_editor.insertHTML(html);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.insertImageBase64String = function(imageBase64String, alt) {
    bbsui_editor.restorerange();
    var html = '<img src="data:image/jpeg;base64,'+imageBase64String+'" alt="'+alt+'" />';
    bbsui_editor.insertHTML(html);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.setHTML = function(html) {
    var editor = $('#bbsui_editor_content');
    editor.html(html);
}

bbsui_editor.insertHTML = function(html) {
    document.execCommand('insertHTML', false, html);
    bbsui_editor.enabledEditingItems();
}

bbsui_editor.getHTML = function() {
    
    // Images
    var img = $('img');
    if (img.length != 0) {
        $('img').removeClass('zs_active');
        $('img').each(function(index, e) {
                      var image = $(this);
                      var zs_class = image.attr('class');
                      if (typeof(zs_class) != "undefined") {
                      if (zs_class == '') {
                      image.removeAttr('class');
                      }
                      }
                      });
    }
    
    // Blockquote
    var bq = $('blockquote');
    if (bq.length != 0) {
        bq.each(function() {
                var b = $(this);
                if (b.css('border').indexOf('none') != -1) {
                b.css({'border': ''});
                }
                if (b.css('padding').indexOf('0px') != -1) {
                b.css({'padding': ''});
                }
                });
    }
    
    // Get the contents
    var h = document.getElementById("bbsui_editor_content").innerHTML;
    
    return h;
}

bbsui_editor.getText = function() {
    return $('#bbsui_editor_content').text();
}

bbsui_editor.isCommandEnabled = function(commandName) {
    return document.queryCommandState(commandName);
}

bbsui_editor.enabledEditingItems = function(e) {
    
    console.log('enabledEditingItems');
    var items = [];
    if (bbsui_editor.isCommandEnabled('bold')) {
        items.push('bold');
    }
    if (bbsui_editor.isCommandEnabled('italic')) {
        items.push('italic');
    }
    if (bbsui_editor.isCommandEnabled('subscript')) {
        items.push('subscript');
    }
    if (bbsui_editor.isCommandEnabled('superscript')) {
        items.push('superscript');
    }
    if (bbsui_editor.isCommandEnabled('strikeThrough')) {
        items.push('strikeThrough');
    }
    if (bbsui_editor.isCommandEnabled('underline')) {
        items.push('underline');
    }
    if (bbsui_editor.isCommandEnabled('insertOrderedList')) {
        items.push('orderedList');
    }
    if (bbsui_editor.isCommandEnabled('insertUnorderedList')) {
        items.push('unorderedList');
    }
    if (bbsui_editor.isCommandEnabled('justifyCenter')) {
        items.push('justifyCenter');
    }
    if (bbsui_editor.isCommandEnabled('justifyFull')) {
        items.push('justifyFull');
    }
    if (bbsui_editor.isCommandEnabled('justifyLeft')) {
        items.push('justifyLeft');
    }
    if (bbsui_editor.isCommandEnabled('justifyRight')) {
        items.push('justifyRight');
    }
    if (bbsui_editor.isCommandEnabled('insertHorizontalRule')) {
        items.push('horizontalRule');
    }
    var formatBlock = document.queryCommandValue('formatBlock');
    if (formatBlock.length > 0) {
        items.push(formatBlock);
    }
    // Images
    $('img').bind('touchstart', function(e) {
                  $('img').removeClass('zs_active');
                  $(this).addClass('zs_active');
                  });
    
    // Use jQuery to figure out those that are not supported
    if (typeof(e) != "undefined") {
        
        // The target element
        var s = bbsui_editor.getSelectedNode();
        var t = $(s);
        var nodeName = e.target.nodeName.toLowerCase();
        
        // Background Color
        var bgColor = t.css('backgroundColor');
        if (bgColor.length != 0 && bgColor != 'rgba(0, 0, 0, 0)' && bgColor != 'rgb(0, 0, 0)' && bgColor != 'transparent') {
            items.push('backgroundColor');
        }
        // Text Color
        var textColor = t.css('color');
        if (textColor.length != 0 && textColor != 'rgba(0, 0, 0, 0)' && textColor != 'rgb(0, 0, 0)' && textColor != 'transparent') {
            items.push('textColor');
        }
		
		//Fonts
		var font = t.css('font-family');
		if (font.length != 0 && font != 'Arial, Helvetica, sans-serif') {
			items.push('fonts');	
		}
		
        // Link
        if (nodeName == 'a') {
            bbsui_editor.currentEditingLink = t;
            var title = t.attr('title');
            items.push('link:'+t.attr('href'));
            if (t.attr('title') !== undefined) {
                items.push('link-title:'+t.attr('title'));
            }
            
        } else {
            bbsui_editor.currentEditingLink = null;
        }
        // Blockquote
        if (nodeName == 'blockquote') {
            items.push('indent');
        }
        // Image
        if (nodeName == 'img') {
            bbsui_editor.currentEditingImage = t;
            items.push('image:'+t.attr('src'));
            if (t.attr('alt') !== undefined) {
                items.push('image-alt:'+t.attr('alt'));
            }
            
        } else {
            bbsui_editor.currentEditingImage = null;
        }
        
    }
    
    if (items.length > 0) {
        if (bbsui_editor.isUsingiOS) {
            //window.location = "bbsui-callback/"+items.join(',');
            window.location = "callback://0/"+items.join(',');
        } else {
            console.log("callback://"+items.join(','));
        }
    } else {
        if (bbsui_editor.isUsingiOS) {
            window.location = "bbsui-callback/";
        } else {
            console.log("callback://");
        }
    }
    
}

bbsui_editor.focusEditor = function() {
    
    // the following was taken from http://stackoverflow.com/questions/1125292/how-to-move-cursor-to-end-of-contenteditable-entity/3866442#3866442
    // and ensures we move the cursor to the end of the editor
    var editor = $('#bbsui_editor_content');
    var range = document.createRange();
    range.selectNodeContents(editor.get(0));
    range.collapse(false);
    var selection = window.getSelection();
    selection.removeAllRanges();
    selection.addRange(range);
    editor.focus();
}

bbsui_editor.blurEditor = function() {
    $('#bbsui_editor_content').blur();
}

bbsui_editor.setCustomCSS = function(customCSS) {
    
    document.getElementsByTagName('style')[0].innerHTML=customCSS;
    
    //set focus
    /*editor.focusout(function(){
                    var element = $(this);
                    if (!element.text().trim().length) {
                    element.empty();
                    }
                    });*/
}

bbsui_editor.getImages = function() {
    
    var imgList = [];
    var imgElements = document.getElementsByTagName("img");
    if (imgElements && imgElements.length > 0) {
        for(var i = 0; i < imgElements.length; i ++) {
            imgList.push(imgElements[i].src);
        }
    }
    if (window.JsInterface) {
        window.JsInterface.onGotImages(imgList);
    }
    return imgList;
}

//end
